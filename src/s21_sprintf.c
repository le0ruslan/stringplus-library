#include "s21_string.h"

sprintf_struct def_sprintf_struct() {
  return (sprintf_struct){false,      false,      SIGN_MINUS,     PARAM_NONE,
                          PARAM_NONE, SIDE_RIGHT, LENGTH_DEFAULT, SPACE_DEFAULT,
                          false,      false,      false};
}

void precision_to_width(sprintf_struct* parameters) {
  if (parameters->width == PARAM_NONE && parameters->precision != PARAM_NONE) {
    parameters->width = parameters->precision;
  }
}

int s21_strcmp(const char* s1, const char* s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void clear_sprintf_struct(sprintf_struct* parameters) {
  parameters->signMode = SIGN_MINUS;
  parameters->space_symbol = ' ';
  parameters->length = LENGTH_DEFAULT;
  parameters->width = PARAM_NONE;
  parameters->precision = PARAM_NONE;
  parameters->side = SIDE_RIGHT;
  parameters->sharp = false;
  parameters->bigChar = false;
  parameters->is_ptr = false;
  parameters->nextIsFormat = false;
}

void flags(sprintf_struct* parameters, char fc) {
  if (fc == 'h') {
    parameters->length = LENGTH_SHORT;
  } else if (fc == 'l') {
    parameters->length = LENGTH_LONG;
  } else if (fc == 'L') {
    parameters->length = LENGTH_LONG_DOUBLE;
  } else if (fc == '-') {
    parameters->side = SIDE_LEFT;
  } else if (fc == '+') {
    parameters->signMode = SIGN_PLUS;
  } else if (fc == ' ') {
    if (parameters->signMode != SIGN_PLUS) parameters->signMode = SIGN_SPACE;
  } else if (fc == '#') {
    parameters->sharp = true;
  } else if (fc == SPACE_ZERO) {
    parameters->space_symbol = SPACE_ZERO;
  }
}

int convert_int(const char** sptr) {
  const char* string = *sptr;
  int result = 0;
  while (*string >= '0' && *string <= '9') {
    result *= 10;
    result += *string - '0';
    string += 1;
  }
  string -= 1;
  *sptr = string;
  return result;
}

void specifiers(sprintf_struct* parameters, char sign, char** sptr, va_list ap,
                int* count) {
  switch (sign) {
    case '%':
      parameters->addChar = true;
      break;
    case 'c':
#ifdef __linux__
      parameters->space_symbol = ' ';
#endif
      *sptr = add_char(*sptr, va_arg(ap, int), parameters);
      break;
    case 's':
#ifdef __linux__
      parameters->space_symbol = ' ';
#endif
#ifdef __linux__
      if (parameters->length == LENGTH_LONG_DOUBLE) *count = -1;
#endif
      if (parameters->length != LENGTH_DEFAULT &&
          parameters->length != LENGTH_SHORT &&
          parameters->length != LENGTH_LONG_DOUBLE)
        *count = -1;
      const char* str = va_arg(ap, char*);
      *sptr = add_str(*sptr, str, parameters);
      break;
    case 'd':
      precision_to_width(parameters);
      if (parameters->length == LENGTH_SHORT)
        *sptr =
            add_int(*sptr, (short)va_arg(ap, int), FORMAT_DECIMAL, parameters);
      else if (parameters->length == LENGTH_LONG)
        *sptr = add_int(*sptr, va_arg(ap, long), FORMAT_DECIMAL, parameters);
      else
        *sptr = add_int(*sptr, va_arg(ap, int), FORMAT_DECIMAL, parameters);
      break;
    case 'f':
      if (parameters->precision == PARAM_NONE)
        parameters->precision = DEFAULT_PRECISION;
      if (parameters->length == LENGTH_LONG_DOUBLE)
        *sptr = add_float(*sptr, va_arg(ap, long double), parameters);
      else
        *sptr = add_float(*sptr, va_arg(ap, double), parameters);
      break;
    case 'o':
    case 'x':
    case 'X':
    case 'u':
      precision_to_width(parameters);
      parameters->signMode = SIGN_NONE;
      int format = FORMAT_DECIMAL;
      if (sign == 'o') {
        format = FORMAT_OCTAL;
      } else if (sign == 'x' || sign == 'X') {
        format = FORMAT_HEX;
        parameters->bigChar = sign == 'X';
      }
      if (parameters->length == LENGTH_SHORT)
        *sptr = add_int(*sptr, (unsigned short)va_arg(ap, unsigned int), format,
                        parameters);
      else if (parameters->length == LENGTH_LONG)
        *sptr = add_int(*sptr, va_arg(ap, unsigned long), format, parameters);
      else
        *sptr = add_int(*sptr, va_arg(ap, unsigned int), format, parameters);
      break;
    case 'p':
      parameters->is_ptr = true;
      parameters->sharp = true;
      if (sizeof(void*) == 32)
        *sptr = add_int(*sptr, va_arg(ap, int32_t), FORMAT_HEX, parameters);
      else
        *sptr = add_int(*sptr, va_arg(ap, int64_t), FORMAT_HEX, parameters);
      break;
    case 'g':
    case 'G':
      if (parameters->precision == PARAM_NONE)
        parameters->precision = DEFAULT_PRECISION;
      else if (parameters->precision == 0)
        parameters->precision = 1;
      if (sign == 'G') parameters->bigChar = true;
      if (parameters->length == LENGTH_LONG_DOUBLE)
        *sptr = add_g(*sptr, va_arg(ap, long double), parameters);
      else
        *sptr = add_g(*sptr, va_arg(ap, double), parameters);
      break;
    case 'e':
    case 'E':
      if (parameters->precision == PARAM_NONE)
        parameters->precision = DEFAULT_PRECISION;
      if (sign == 'E') parameters->bigChar = true;
      if (parameters->length == LENGTH_LONG_DOUBLE)
        *sptr = add_e(*sptr, va_arg(ap, long double), parameters);
      else
        *sptr = add_e(*sptr, va_arg(ap, double), parameters);
      break;
  }
}

int s21_sprintf(char* str, const char* format, ...) {
  sprintf_struct parameters = def_sprintf_struct();
  va_list ap;
  va_start(ap, format);
  int count = 0;
  char* sptr = str;
  for (const char* fptr = format; *fptr != '\0' && count >= 0; ++fptr) {
    char sign = *fptr;
    if (parameters.nextIsFormat) {
      if (sign == 'h' || sign == 'l' || sign == 'L' || sign == '-' ||
          sign == '+' || sign == ' ' || sign == '#' || sign == SPACE_ZERO)
        flags(&parameters, sign);
      else if (sign == PARAM_ARG)
        parameters.width = va_arg(ap, int);
      else if (isdigit(sign)) {
        parameters.width = convert_int(&fptr);
      } else if (sign == '.') {
        sign = *++fptr;
        if (sign == PARAM_ARG) {
          parameters.precision = va_arg(ap, int);
        } else if (isdigit(sign)) {
          parameters.precision = convert_int(&fptr);
        } else {
          fptr -= 1;
          parameters.precision = 0;
        }
      } else {
        specifiers(&parameters, sign, &sptr, ap, &count);
        clear_sprintf_struct(&parameters);
      }
    } else if (sign == '%')
      parameters.nextIsFormat = true;
    else
      parameters.addChar = true;
    if (parameters.addChar) {
      *sptr++ = sign;
      parameters.addChar = false;
    }
  }
  *sptr = '\0';
  va_end(ap);
  if (count >= 0)
    count = sptr - str;
  else
    *str = '\0';
  return count;
}

int find_e(long double* nump) {
  int ex = 0;
  long double number = *nump;
  int inc = -1;
  long double cutt = 10.0L;
  if (number >= 10.0L) {
    inc = 1;
    cutt = 0.1L;
  }
  if (number != 0.0L) {
    while (number < 1 || number >= 10) {
      number *= cutt;
      ex += inc;
    }
  }
  *nump = number;
  return ex;
}

void string_reverse(char* string, int n) {
  for (int i = 0; i < n / 2; ++i) {
    char temp = string[i];
    string[i] = string[n - i - 1];
    string[n - i - 1] = temp;
  }
}

int num_len(long long number, int format) {
  int length = 1;
  if (number > 0) {
    length = 0;
    while (number > 0) {
      number /= format;
      length += 1;
    }
  }
  return length;
}

int float_left_length(long double number) {
  int length = 0;
  if (number == 0) length = 1;
  while (number > 0) {
    number = floorl(number / 10);
    length += 1;
  }
  if (length == 0) length = 1;
  return length;
}

int end_zeros_count(long double number, int precision) {
  for (int i = 0; i < precision; ++i) number *= 10.0L;
  int count = 0;
  if (number == 0.0L) count = 1000000;
  number = roundl(number);
  bool pass = true;
  while (number > 0.0L && pass) {
    pass = fmodl(number, 10) == 0.0L;
    if (pass) {
      count += 1;
      number /= 10.0L;
    }
  }
  return count;
}

char* print_format(char* string, int format, bool bigChar) {
  if (format != FORMAT_DECIMAL) *string++ = '0';
  if (format == FORMAT_HEX) *string++ = bigChar ? 'X' : 'x';
  return string;
}

char* add_char(char* string, long symbol, sprintf_struct* parameters) {
  int length = parameters->width - 1;
  if (parameters->side == SIDE_RIGHT) {
    for (int i = 0; i < length; i++) *string++ = parameters->space_symbol;
  }
  *string++ = symbol;
  if (parameters->side == SIDE_LEFT) {
    for (int i = 0; i < length; i++) *string++ = SPACE_DEFAULT;
  }
  return string;
}

char* add_int(char* string, long long number, int format,
              sprintf_struct* parameters) {
  char sign_char = '\0';
  if (parameters->signMode != SIGN_NONE) {
    if (number < 0.0L)
      sign_char = '-';
    else if (parameters->signMode == SIGN_PLUS)
      sign_char = '+';
    else if (parameters->signMode == SIGN_SPACE)
      sign_char = ' ';
  }
  if (format != FORMAT_DECIMAL) sign_char = '\0';
  if (sign_char != '\0') parameters->width -= 1;
  if (number < 0) number = -number;
  int numlen = num_len(number, format);
  int lenA = parameters->width - numlen;
  if (number == 0 && parameters->precision == 0) lenA += 1;

  if (parameters->sharp) {
    if (format == FORMAT_OCTAL)
      lenA -= 1;
    else if (format == FORMAT_HEX)
      lenA -= 2;
  }
  int zeros = 0;
  if (parameters->precision != PARAM_NONE)
    zeros = parameters->precision - numlen;
  else if (parameters->space_symbol == SPACE_ZERO &&
           parameters->side == SIDE_RIGHT)
    zeros = lenA;
  if (zeros < 0) zeros = 0;
  lenA -= zeros;
  if (parameters->side == SIDE_RIGHT) {
    for (int i = 0; i < lenA; ++i) *string++ = SPACE_DEFAULT;
  }
  if (sign_char != '\0') *string++ = sign_char;
  if ((parameters->sharp && number != 0) || parameters->is_ptr) {
    if (format == FORMAT_OCTAL) zeros -= 1;
    string = print_format(string, format, parameters->bigChar);
  }
  for (int i = 0; i < zeros; ++i) *string++ = SPACE_ZERO;
  if (number != 0 || parameters->precision != 0) {
    char* num_ptr = string;
    do {
      char sim = number % format;
      if (sim < FORMAT_DECIMAL) {
        sim += '0';
      } else {
        sim += 'a' - 10;
        if (parameters->bigChar) sim -= 'a' - 'A';
      }
      *string++ = sim;
      number /= format;
    } while (number > 0);
    string_reverse(num_ptr, numlen);
  }
  if (parameters->side == SIDE_LEFT) {
    for (int i = 0; i < lenA; ++i) *string++ = ' ';
  }
  return string;
}

char* add_str(char* result, const char* string, sprintf_struct* parameters) {
  if (string == NULL) {
    string = "(null)";
#ifdef __linux__
    if (parameters->precision <= 6 && parameters->precision != PARAM_NONE)
      parameters->precision = 0;
#endif
  }
  if ((s21_strcmp(string, "nan") == 0) || (s21_strcmp(string, "-inf") == 0) ||
      (s21_strcmp(string, "inf") == 0)) {
    parameters->space_symbol = ' ';
  }
  int length = s21_strlen(string);
  if (parameters->precision != PARAM_NONE && length > parameters->precision)
    length = parameters->precision;
  int lenA = parameters->width - length;

  if (lenA > 0 && parameters->side == SIDE_RIGHT) {
    for (int i = 0; i < lenA; i++) *result++ = parameters->space_symbol;
  }
  for (const char* ptr = string;
       *ptr != '\0' && (parameters->precision == PARAM_NONE ||
                        ptr - string < parameters->precision);
       ++ptr) {
    *result++ = *ptr;
  }
  if (lenA > 0 && parameters->side == SIDE_LEFT) {
    for (int i = 0; i < lenA; i++) *result++ = ' ';
  }
  return result;
}

char* add_float(char* string, long double number, sprintf_struct* parameters) {
  if (number == INFINITY) {
    string = add_str(string, "inf", parameters);
  } else if (number == -INFINITY) {
    string = add_str(string, "-inf", parameters);
  } else if (isnan(number)) {
    string = add_str(string, "nan", parameters);
  } else {
    char sign = '\0';
    if (number < 0.0L)
      sign = '-';
    else if (parameters->signMode == SIGN_PLUS)
      sign = '+';
    else if (parameters->signMode == SIGN_SPACE)
      sign = ' ';
    int width = parameters->width;
    if (sign != '\0') width -= 1;
    if (number < 0) number = -number;
    long double num_left = floorl(number);
    int num_left_length = float_left_length(num_left);
    int len = num_left_length;
    if (parameters->precision > 0) len += parameters->precision;
    if (parameters->precision > 0 || parameters->sharp) len += 1;
    for (int i = 0; i < parameters->precision; i++) number *= 10;
    number = roundl(number);
    int lenA = width - len;
    if (sign != '\0' && parameters->space_symbol == SPACE_ZERO)
      *string++ = sign;
    if (lenA > 0 && parameters->side == SIDE_RIGHT) {
      for (int i = 0; i < lenA; ++i) *string++ = parameters->space_symbol;
    }
    if (sign != '\0' && parameters->space_symbol == SPACE_DEFAULT)
      *string++ = sign;
    char* nptr = string;
    if (parameters->precision > 0) {
      for (int i = 0; i < parameters->precision; i++) {
        *string++ = (int)fmodl(number, 10) + '0';
        number = floorl(number / 10);
      }
    }
    if (parameters->precision > 0 || parameters->sharp) *string++ = '.';
    for (int j = 0; j < num_left_length; j++) {
      *string++ = (int)fmodl(number, 10) + '0';
      number = floorl(number / 10);
    }
    string_reverse(nptr, len);
    if (lenA > 0 && parameters->side == SIDE_LEFT) {
      for (int j = 0; j < lenA; j++) *string++ = SPACE_DEFAULT;
    }
  }
  return string;
}

char* add_e(char* string, long double number, sprintf_struct* parameters) {
  if (number == INFINITY) {
    string = add_str(string, "inf", parameters);
  } else if (number == -INFINITY) {
    string = add_str(string, "-inf", parameters);
  } else if (isnan(number)) {
    string = add_str(string, "nan", parameters);
  } else {
    bool has_sign = false;
    if (number < 0) {
      has_sign = true;
      number = -number;
    }
    int expo = find_e(&number);
    int expo_width = 4;
    if (expo >= 100) expo_width += 1;
    parameters->width -= expo_width;
    if (parameters->width < 0) parameters->width = PARAM_NONE;
    if (has_sign) number = -number;
    int side = parameters->side;
    if (side == SIDE_LEFT) parameters->side = PARAM_NONE;
    char* nptr = string;
    string = add_float(string, number, parameters);
    int writed = string - nptr;
    nptr = string;
    char expo_sign = expo < 0 ? '-' : '+';
    if (expo < 0) expo = -expo;
    int e = expo;
    do {
      *string++ = e % 10 + '0';
      e /= 10;
    } while (e > 0);
    if (expo < 10) *string++ = '0';
    *string++ = expo_sign;
    *string++ = parameters->bigChar ? 'E' : 'e';
    string_reverse(nptr, expo_width);
    if (side == SIDE_LEFT) {
      int lenA = parameters->width - writed;
      if (lenA < 0) lenA = 0;
      for (int i = 0; i < lenA; i++) *string++ = SPACE_DEFAULT;
    }
  }

  return string;
}

char* add_g(char* string, long double number, sprintf_struct* parameters) {
  if (number == INFINITY) {
    string = add_str(string, "inf", parameters);
  } else if (number == -INFINITY) {
    string = add_str(string, "-inf", parameters);
  } else if (isnan(number)) {
    string = add_str(string, "nan", parameters);
  } else {
    bool has_sign = number < 0.0L;
    if (has_sign) number = -number;
    long double expo_num = number;
    int expo = find_e(&expo_num);
    int numl_len = float_left_length(number);
    if (parameters->precision > expo && expo > -4) {
      parameters->precision -= numl_len;
      if (parameters->precision > 0 && !parameters->sharp)
        parameters->precision -= end_zeros_count(number, parameters->precision);
      if (parameters->precision < 0) parameters->precision = PARAM_NONE;
      if (has_sign) number = -number;
      string = add_float(string, number, parameters);
    } else {
      parameters->precision -= 1;
      if (parameters->precision < 0) parameters->precision = PARAM_NONE;
      if (has_sign) number = -number;
      string = add_e(string, number, parameters);
    }
  }
  return string;
}
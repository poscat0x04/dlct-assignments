#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint8_t const OFFSET_COMMON[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
uint8_t const OFFSET_LEAP[] = {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
uint8_t const DAYS_IN_MONTH_COMMON[] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
uint8_t const DAYS_IN_MONTH_LEAP[] = {31, 29, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};

void printHeader(void);
uint8_t jan1DayOfWeek(uint16_t);
bool isLeapYear(uint16_t);
uint8_t firstDayOfWeek(uint16_t, uint8_t);
void printInitWS(uint8_t);
void printDay(uint8_t, uint8_t, bool);
void printCalendarBody(uint8_t, uint8_t);

void printHeader() { printf("Sun Mon Tue Wed Thu Fri Sat\n"); }

uint8_t jan1DayOfWeek(uint16_t year) {
  return (1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) +
          6 * ((year - 1) % 400)) %
         7;
}

bool isLeapYear(uint16_t year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
}

uint8_t firstDayOfWeek(uint16_t year, uint8_t month) {
  if (isLeapYear(year)) {
    return (jan1DayOfWeek(year) + OFFSET_LEAP[month - 1]) % 7;
  } else {
    return (jan1DayOfWeek(year) + OFFSET_COMMON[month - 1]) % 7;
  }
}

void printInitWS(uint8_t dayOfWeek) {
  for (uint8_t i = 0; i < dayOfWeek; i++) {
    fputs("    ", stdout);
  }
}

void printDay(uint8_t offset, uint8_t dayOfMonth, bool trailingWs) {
  printf("%2d", dayOfMonth);
  if (trailingWs) {
    putchar(' ');
    if ((offset + dayOfMonth) % 7 == 0) {
      putchar('\n');
    } else {
      putchar(' ');
    }
  }
}

void printCalendarBody(uint8_t dayOfWeek, uint8_t dayCount) {
  printInitWS(dayOfWeek);
  for (uint8_t dayOfMonth = 1; dayOfMonth < dayCount; dayOfMonth++) {
    printDay(dayOfWeek, dayOfMonth, true);
  }
  printDay(dayOfWeek, dayCount, false);
};

int main(void) {
  uint16_t year;
  uint8_t month;
  scanf("%" SCNu16 "%" SCNu8, &year, &month);
  uint8_t dayOfWeek = firstDayOfWeek(year, month);
  printHeader();
  if (isLeapYear(year)) {
    printCalendarBody(dayOfWeek, DAYS_IN_MONTH_LEAP[month - 1]);
  } else {
    printCalendarBody(dayOfWeek, DAYS_IN_MONTH_COMMON[month - 1]);
  }
  return 0;
}

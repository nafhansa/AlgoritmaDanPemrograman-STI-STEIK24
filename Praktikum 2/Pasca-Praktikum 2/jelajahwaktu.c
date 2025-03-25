#include <stdio.h>
#include <string.h>

/**
 * @brief Struktur untuk merepresentasikan tanggal.
 */
typedef struct {
    int day;   /**< day (tipe data: int) */
    int month; /**< month (tipe data: int) */
    int year;  /**< year (tipe data: int) */
} Date;

/**
 * @brief Fungsi untuk mengecek apakah tahun adalah tahun kabisat.
 */
int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

/**
 * @brief Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu.
 */
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) return 29;
    return daysInMonth[month - 1];
}

/**
 * @brief Fungsi untuk menghitung jumlah hari sejak 1 Januari tahun 1.
 */
int daysSinceBeginning(Date date) {
    int days = date.day;

    for (int y = 1; y < date.year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < date.month; m++) {
        days += getDaysInMonth(m, date.year);
    }

    return days;
}

/**
 * @brief Fungsi untuk menambahkan n hari ke tanggal.
 */
Date addDays(Date date, int n) {
    date.day += n;

    while (date.day > getDaysInMonth(date.month, date.year)) {
        date.day -= getDaysInMonth(date.month, date.year);
        date.month++;

        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    
    return date;
}

/**
 * @brief Fungsi untuk mendapatkan indeks hari dalam seminggu.
 */
int getDayOfWeekAsIndex(Date date) {
    int days = daysSinceBeginning(date);
    return (days + 0) % 7; // 1 Januari tahun 1 adalah Senin (index 1)
}

/* FUNGSI - FUNGSI DI BAWAH INI TIDAK PERLU DIUBAH */

static const char *months[] = {"Januari",   "Februari", "Maret",    "April",
                               "Mei",       "Juni",     "Juli",     "Agustus",
                               "September", "Oktober",  "November", "Desember"};
static const char *days[] = {"Minggu", "Senin", "Selasa", "Rabu",
                             "Kamis",  "Jumat", "Sabtu"};

/**
 * @brief Fungsi untuk mendapatkan nama hari dari tanggal tertentu.
 */
const char *getDayOfWeek(Date date) {
    int dayIndex = getDayOfWeekAsIndex(date);
    return days[dayIndex];
}

/**
 * @brief Fungsi untuk mencetak tanggal dalam format yang diinginkan.
 */
void printDate(Date date) {
    printf("%s, %d %s %d\n", getDayOfWeek(date), date.day,
           months[date.month - 1], date.year);
}

/**
 * @brief Fungsi untuk mengonversi string bulan ke angka.
 */
int getMonthNumber(const char *monthStr) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthStr, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; // Bulan tidak valid
}

/**
 * @brief Fungsi untuk mengonversi string tanggal ke struct Date.
 */
Date parseDate(const char *dateStr) {
    Date date;
    char monthStr[10];
    sscanf(dateStr, "%d %s %d", &date.day, monthStr, &date.year);
    date.month = getMonthNumber(monthStr);

    if (date.month == -1) {
        printf("Bulan tidak valid!\n");
    }
    return date;
}

/**
 * @brief Fungsi utama untuk menjalankan program.
 */
int main() {
    char inputDate[30];
    int n;

    fgets(inputDate, sizeof(inputDate), stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;
    scanf("%d", &n);

    Date date;
    date = parseDate(inputDate);

    date = addDays(date, n);
    printDate(date);

    return 0;
}

#pragma once

#include <FuGPS.h>

struct TelescopePosition {
	float altitude;
	float latitude;
	float longitude;
};


struct RaDecPosition {
	double rightAscension;
	double declination;
};

const double pi = 3.14159265358979324;

int days_since_j2k(int year);
int days_to_beginning_of_month(int year, int month);
double get_local_sidereal_time(const double degrees_longitude);
double get_hour_angle(const double local_sidereal_time, const double degrees_right_ascension);

void loadFromEEPROM();
void updateEEPROM(float altitude, float latitude, float longitude, int hours,
		int minutes, int seconds);
TelescopePosition& initGPS(FuGPS &gps);
TelescopePosition& handleGPS(FuGPS &gps);

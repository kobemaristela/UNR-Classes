#ifndef PROJ4_SENSOR_H
#define PROJ4_SENSOR_H

#include <iostream>
#include <fstream>
#include "StringFunctions.h"
using namespace std;

class Sensor{
public:
    //Constructors
    Sensor();
    Sensor(const char *type);
    Sensor(const Sensor &copy);

    //Getters
    const char *getM_type() const;
    float getM_extracost() const;
    static int getGps_cnt();
    static int getCamera_cnt();
    static int getLidar_cnt();
    static int getRadar_cnt();

    //Setters
    void setM_extracost(float m_extracost);
    void setM_type(const char* source);
    static void resetGps_cnt();
    static void resetCamera_cnt();
    static void resetLidar_cnt();
    static void resetRadar_cnt();

    //Overload Operator
    bool operator==(const Sensor &rhs) const;

    //Functions
    void extraCost();
    int sensorCount();

private:
    char m_type[256];
    float m_extracost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;
};

#endif //PROJ4_SENSOR_H

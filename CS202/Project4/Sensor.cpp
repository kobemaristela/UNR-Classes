#include "Sensor.h"

//Default Constructor
Sensor::Sensor()
{
    setM_type("none");
    setM_extracost(0.0);
}

//Parameterized Constructor
Sensor::Sensor(const char *type)
{
    setM_type(type);
    setM_extracost(0.0);
    extraCost();
}

//Copy Constructor
Sensor::Sensor(const Sensor &copy)
{
    setM_type(copy.m_type);
    setM_extracost(copy.m_extracost);
}

//Getters
const char *Sensor::getM_type() const {
    return m_type;
}

float Sensor::getM_extracost() const {
    return m_extracost;
}

int Sensor::getGps_cnt() {
    return gps_cnt;
}

int Sensor::getCamera_cnt() {
    return camera_cnt;
}

int Sensor::getLidar_cnt() {
    return lidar_cnt;
}

int Sensor::getRadar_cnt() {
    return radar_cnt;
}

//Setters
void Sensor::setM_extracost(float m_extracost) {
    Sensor::m_extracost = m_extracost;
}

void Sensor::setM_type(const char* source)
{
    myStringCopy(m_type, source);
}

void Sensor::resetGps_cnt()
{
    gps_cnt = 0;
}

void Sensor::resetCamera_cnt()
{
    camera_cnt = 0;
}

void Sensor::resetLidar_cnt() {
    lidar_cnt = 0;
}

void Sensor::resetRadar_cnt() {
    radar_cnt = 0;
}

//Operators
bool Sensor::operator==(const Sensor &rhs) const
{
    return (!myStringCompare(m_type, rhs.m_type)) == 1;
}

//Functions
void Sensor::extraCost() {
    if (!myStringCompare(m_type, "gps") == 1)
    {
        m_extracost += 5.0;
        gps_cnt++;
    }
    if (!myStringCompare(m_type, "camera") == 1)
    {
        m_extracost += 10.0;
        camera_cnt++;
    }
    if (!myStringCompare(m_type, "lidar") == 1)
    {
        m_extracost += 15.0;
        lidar_cnt++;
    }
    if (!myStringCompare(m_type, "radar") == 1)
    {
        m_extracost += 20.0;
        radar_cnt++;
    }
}

int Sensor::sensorCount() {
    return getGps_cnt() + getCamera_cnt() + getLidar_cnt() + getRadar_cnt();
}


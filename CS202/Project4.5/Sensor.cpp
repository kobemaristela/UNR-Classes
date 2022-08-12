#include "Sensor.h"

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

//Default Constructor
Sensor::Sensor()
{
    setM_type("none");
    setM_extracost(0.0);
}

//Parameterized Constructor
Sensor::Sensor(const char *type)
{
    if (!(myStringCompare(type, " ")))
    {
        setM_type("none");
    } else{
        setM_type(type);
    }
    setM_extracost(0.0);
    extraCost();
    //cout << "M-type: " << m_type << endl;
    //cout << "myCompare: " << myStringCompare(m_type, "gps") << endl;
    //cout << "OSensor: " << getGps_cnt() << ", " << getCamera_cnt() << ", " << getLidar_cnt() << ", " << getRadar_cnt()<< endl;
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
    return !(myStringCompare(m_type, rhs.m_type));
}

//Functions
void Sensor::extraCost() {
    if ((myStringCompare(m_type, "gps")) == 79)
    {
        m_extracost += 5.0;
        gps_cnt++;
    }
    if (!(myStringCompare(m_type, "camera")))
    {
        m_extracost += 10.0;
        camera_cnt++;
    }
    if (!(myStringCompare(m_type, "lidar")))
    {
        m_extracost += 15.0;
        lidar_cnt++;
    }
    if (!(myStringCompare(m_type, "radar")))
    {
        m_extracost += 20.0;
        radar_cnt++;
    }
}

int Sensor::sensorCount() {
    return getGps_cnt() + getCamera_cnt() + getLidar_cnt() + getRadar_cnt();
}


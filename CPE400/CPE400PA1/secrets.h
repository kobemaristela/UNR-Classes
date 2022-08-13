#include <pgmspace.h>

#define SECRET
#define THINGNAME "KAR-pi"

//fill in with WIFI SSID and Password
//not the best way to store it but it works
const char WIFI_SSID[] = "UNR-IOT";
const char WIFI_PASSWORD[] = "/*REDACTED*\";
const char AWS_IOT_ENDPOINT[] = '/*REDACTED*\';

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
"/*REDACTED*\"
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
"/*REDACTED*\"
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
"/*REDACTED*\"
)KEY";

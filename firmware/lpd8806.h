// This file was modified by Jeff Glancy (https://github.com/jeffglancy)
//  in order to work with Particle Photon & RedBear Duo

#ifndef __lpd8806_H__
#define __lpd8806_H__

#include "application.h"

class lpd8806 {

 public:

  lpd8806(uint16_t n, uint8_t spi_num); // Select which SPI hardware port; 0 or 1
  lpd8806(uint16_t n); // Use SPI hardware; SPI 0 pins only
  lpd8806(void); // Empty constructor; init pins & strip length later
  void
    begin(void),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    show(void),
    updatePins(uint8_t spi_num), // Change pins, hardware SPI port
    updateLength(uint16_t n);               // Change strip length
  uint16_t
    numPixels(void);
  uint32_t
    Color(byte, byte, byte),
    getPixelColor(uint16_t n);

 private:

  uint16_t
    numLEDs,    // Number of RGB LEDs in strip
    numBytes;   // Size of 'pixels' buffer below
  uint8_t
    *pixels,    // Holds LED color values (3 bytes each) + latch bytes
    spi_port;     // SPI hardware port
  void
    startSPI(void);
  boolean
    begun;       // If 'true', begin() method was previously invoked
};

#endif
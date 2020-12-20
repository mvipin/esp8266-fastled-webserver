/*
   Sol: https://github.com/evilgeniuslabs/sol
   Copyright (C) 2016 Jason Coon, Evil Genius Labs

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

void drawPolarNoise(CRGBPalette16 palette, uint8_t hueReduce = 0)
{
  for (uint8_t ringIndex = 0; ringIndex < ringCount; ringIndex++) { // y
    uint16_t ringStart = rings[ringIndex][0];
    uint16_t ringEnd = rings[ringIndex][1];
    
    for (uint16_t i = ringStart; i <= ringEnd; i++) { // x
      uint8_t x = (i - ringStart) * (256 / (ringEnd - ringStart));
      uint8_t y = ringIndex * (128 / ringCount);
      
      int xoffset = noisescale * x;
      int yoffset = noisescale * y;

      uint8_t data = inoise8(x + xoffset + noisex, y + yoffset + noisey, noisez);
  
      // The range of the inoise8 function is roughly 16-238.
      // These two operations expand those values out to roughly 0..255
      // You can comment them out if you want the raw noise data.
      data = qsub8(data, 16);
      data = qadd8(data, scale8(data, 39));
  
      leds[i] = ColorFromPalette(palette, data, 255, LINEARBLEND);
    }

//    if(ringIndex != 0) {
//      // blend the first pixel in the ring into the last
//      nblend(leds[ringStart], leds[ringEnd], 192);
//      nblend(leds[ringStart + 1], leds[ringEnd - 1], 128);
//      nblend(leds[ringStart + 2], leds[ringEnd - 2], 64);
//    }
  }
  
  noisex += noisespeedx;
  noisey += noisespeedy;
  noisez += noisespeedz;
}

void gradientPalettePolarNoise() {
  noisespeedx = 4;
  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(gCurrentPalette);
}

void palettePolarNoise() {
  noisespeedx = 9;
  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(palettes[currentPaletteIndex]);
}

void rainbowPolarNoise() {
  noisespeedx = 0;
  noisespeedy = 2;
  noisespeedz = 0;
  noisescale = 0;
  colorLoop = 0;
  drawPolarNoise(RainbowColors_p);
}

void rainbowStripePolarNoise() {
  noisespeedx = 0;
  noisespeedy = 2;
  noisespeedz = 0;
  noisescale = 0;
  colorLoop = 0;
  drawPolarNoise(RainbowStripeColors_p);
}

void partyPolarNoise() {
  noisespeedx = 9;
  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(PartyColors_p);
}

void forestPolarNoise() {
  noisespeedx = 9;
  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(ForestColors_p);
}

void cloudPolarNoise() {
  noisespeedx = 2;
  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 0;
  colorLoop = 0;
  drawPolarNoise(CloudColors_p);
}

void firePolarNoise() {
//  noisespeedx = 0; // 24;
//  noisespeedy = -24;
//  noisespeedz = 0;
//  noisescale = 4;
//  colorLoop = 0;
  noisespeedx = 0; // 24;
  noisespeedy = -32;
  noisespeedz = 0;
  noisescale = 4;
  colorLoop = 0;
  drawPolarNoise(HeatColors_p, 60);
}

void firePolarNoise2() {
//  noisespeedx = 0;
//  noisespeedy = -8;
//  noisespeedz = 4;
//  noisescale = 1;
//  colorLoop = 0;
  noisespeedx = 0;
  noisespeedy = -4;
  noisespeedz = 4;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(HeatColors_p);
}

void lavaPolarNoise() {
  noisespeedx = 0;
  noisespeedy = -1;
  noisespeedz = 1;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(LavaColors_p);
}

void oceanPolarNoise() {
  noisespeedx = -1; // beatsin8(6, 0, 2) - 1;
  noisespeedy = 0;
  noisespeedz = 1;
  noisescale = 0;
  colorLoop = 0;
  drawPolarNoise(OceanColors_p);
}

void blackAndWhitePolarNoise() {
  SetupBlackAndWhiteStripedPalette();
  noisespeedx = -4; // beatsin8(8, 0, 9) - 4;
  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 0;
  colorLoop = 0;
  drawPolarNoise(blackAndWhiteStripedPalette);
}

void blackAndBluePolarNoise() {
  SetupBlackAndBlueStripedPalette();
  noisespeedx = 0;
  noisespeedy = -8; // beatsin8(8, 0, 16) - 8;
  noisespeedz = 0;
  noisescale = 1;
  colorLoop = 0;
  drawPolarNoise(blackAndBlueStripedPalette);
}
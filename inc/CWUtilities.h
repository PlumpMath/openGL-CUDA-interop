//
//  CWUtilities.h
//  
//
//  Created by Christopher Watkins on 27/06/13.
//
//

#ifndef _CWUtilities_h
#define _CWUtilities_h

#include "CWOpenGL.h"

// Screen constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS    = 60;

// Color modes
const int COLOUR_MODE_CYAN  = 0;
const int COLOUR_MODE_MULTI = 1;

// Utility function declarations

bool initialiseGL( void );
// Pre Condition:
//   -A valid OpenGL context
// Post Condition:
//   -Initializes matrices and clear colour
//   -Reports to console if there was an OpenGL error
//   -Returns false if there was an error in initialization
// Side Effects:
//   -Projection matrix is set to identity matrix
//   -Modelview matrix is set to identity matrix
//   -Matrix mode is set to modelview
//   -Clear colour is set to black

void updateBuffer( void );
// Pre Condition:
//   -None
// Post Condition:
//   -Does per frame logic
// Side Effects:
//   -None

void renderBuffer( void );
// Pre Condition:
//   -A valid OpenGL context
//   -Active modelview matrix
// Post Condition:
//   -Renders the scene
// Side Effects:
//   -Clears the colour buffer
//   -Swaps the front/back buffer
//   -Sets matrix mode to modelview
//   -Translates modelview matrix to the center of the default screen
//   -Changes the current rendering colour

void handleKeys( unsigned char key, int x, int y );
// Pre Condition:
//   -Node
// Post Condition:
//   -Toggles the colour mode when the user presses q
//   -Cycles through different projection scales when the user presses e
// Side Effects:
//   -If the user presses e, the matrix mode is set to projection


#endif

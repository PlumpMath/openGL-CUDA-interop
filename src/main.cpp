//
//  main.cpp
//  openGL
//
//  Created by Christopher Watkins on 27/06/13.
//  Copyright (c) 2013 Christopher Watkins. All rights reserved.
//

#include "CWUtilities.h"

// Function declarations

void runMainLoop( int val );
// Pre Condition:
//   -Initialized freeGLUT
// Post Condition:
//   -Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
// Side Effects:
//   -Sets glutTimerFunc

int main( int argc, char *args[] ) {
    // Initialise freeGLUT
    glutInit( &argc, args );
    
    // Create OpenGL 2.1 context
    glutInitContextVersion( 2, 1 );
    
    // Create a double buffered window
    glutInitDisplayMode( GLUT_DOUBLE );
    glutInitWindowSize ( SCREEN_WIDTH, SCREEN_HEIGHT );
    glutCreateWindow   ( "OpenGL - Serious OpenGL programming" );
    
    // Post window/context creation initialisation
    if ( !initialiseGL( ) ) {
        printf( "Unable to initialise graphics library!\n" );
        return 1;
    }
    
    // Set keyboard handler
    glutKeyboardFunc( handleKeys );
    
    // Set rendering function
    glutDisplayFunc( renderBuffer );
    
    // Set main loop
    glutTimerFunc( 100 / SCREEN_FPS, runMainLoop, 0 );
    
    // Start GLUT main loop
    glutMainLoop( );
    
    return 0;
}

void runMainLoop ( int val ) {
    // Frame logic
    updateBuffer();
    renderBuffer();
    
    // Run frame one more time
    glutTimerFunc( 100 / SCREEN_FPS, runMainLoop, val );
}
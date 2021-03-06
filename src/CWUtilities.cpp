//
//  CWUtilities.cpp
//  openGL
//
//  Created by Christopher Watkins on 27/06/13.
//  Copyright (c) 2013 Christopher Watkins. All rights reserved.
//

#include "CWUtilities.h"

// The current color rendering mode
int gColourMode = COLOUR_MODE_CYAN;

// The projection scale
GLfloat gProjectionScale = 1.f;

bool initialiseGL( void ) {
    // Initialise projection matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );
    
    // Initialize modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    
    // Initialise clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );
    
    // Check for error
    GLenum error = glGetError( );
    if( error != GL_NO_ERROR ) {
        printf( "Error initialising OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }
    
    return true;
}

void updateBuffer( void ) {
    
}

void renderBuffer( void ) {
    // Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );
    
    // Reset modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    
    // Move to center of the screen
    glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );
    
    // Render QUAD
    if (gColourMode == COLOUR_MODE_CYAN ) {
        // Solid Cyan
        glBegin( GL_QUADS );
            glColor3f ( 0.f, 1.f, 1.f);
            glVertex2f( -50.f, -50.f );
            glVertex2f(  50.f, -50.f );
            glVertex2f(  50.f,  50.f );
            glVertex2f( -50.f,  50.f );
        glEnd( );
    }
    else {
        // RYGB Mix
        glBegin( GL_QUADS );
            glColor3f( 1.f, 0.f, 0.f ); glVertex2f( -50.f, -50.f );
            glColor3f( 1.f, 1.f, 0.f ); glVertex2f(  50.f, -50.f );
            glColor3f( 0.f, 1.f, 0.f ); glVertex2f(  50.f,  50.f );
            glColor3f( 0.f, 0.f, 1.f ); glVertex2f( -50.f,  50.f );
        glEnd( );
    }
        
    // Update screen
    glutSwapBuffers( );
    
}

void handleKeys( unsigned char key, int x, int y ) {
    // If the user presses q
    if( key == 'q' ) {
        // Toggle color mode
        if( gColourMode == COLOUR_MODE_CYAN ) {
            gColourMode = COLOUR_MODE_MULTI;
        }
        else {
            gColourMode = COLOUR_MODE_CYAN;
        }
    }
    else if( key == 'e' ) {
        // Cycle through projection scales
        if( gProjectionScale == 1.f ) {
            // Zoom out
            gProjectionScale = 2.f;
        }
        else if( gProjectionScale == 2.f ) {
            // Zoom in
            gProjectionScale = 0.5f;
        }
        else if( gProjectionScale == 0.5f ) {
            //Regular zoom
            gProjectionScale = 1.f;
        }
        
        // Update projection matrix
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity( );
        glOrtho( 0.0, SCREEN_WIDTH * gProjectionScale, SCREEN_HEIGHT * gProjectionScale, 0.0, 1.0, -1.0 );
    }
}

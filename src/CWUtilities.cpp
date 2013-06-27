//
//  CWUtilities.cpp
//  openGL
//
//  Created by Christopher Watkins on 27/06/13.
//  Copyright (c) 2013 Christopher Watkins. All rights reserved.
//

#include "CWUtilities.h"

bool initialiseGL( void ) {
    // Initialise projection matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    
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
    
    // Render QUAD
    glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f(  0.5f, -0.5f );
        glVertex2f(  0.5f,  0.5f );
        glVertex2f( -0.5f,  0.5f );
    glEnd( );
    
    // Update screen
    glutSwapBuffers( );
    
}

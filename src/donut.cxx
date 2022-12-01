#pragma once

#include "donut.hxx"
#include <stdio.h>
#include <string.h>
#include <cmath>

Donut::Donut()

{ }

// Recall that `this` is a `const Ball*`, and you can create a copy of a ball
// with the copy constructor. So to get a new `Ball` to return, you can write
//
//     Ball result(*this);
//
void
Donut::rotate()
{

    std::cout << "here";
    int k;
    // double sin() ,cos();
    // void delay(int number_of_seconds)
    // {
    //     int milli_seconds = 1000 * number_of_seconds;
    //     clock_t start_time = clock();
    //     while (clock() < start_time + milli_seconds)
    //         ;
    // }

    int screen_width = 1760;
    float A=0, B=0, i, j, z[screen_width];
    char b[screen_width];
    printf("[2J");
    for( ; ; ) {
        // delay(30);//delay can be changed as per requirement to speed up the trasitions

        // int milli_seconds = 1000 * 30;
        // clock_t start_time = clock();
        // while (clock() < start_time + milli_seconds)
        //     ;

        memset(b,32,screen_width);
        memset(z,0,7040);
        for(j=0; 2*M_PI>j; j+=0.07) {
            for(i=0; 2*M_PI >i; i+=0.02) {
                float sini=sin(i),
                        cosj=cos(j),
                        sinA=sin(A),
                        sinj=sin(j),
                        cosA=cos(A),
                        cosj2=cosj+2,
                        mess=1/(sini*cosj2*sinA+sinj*cosA+5),
                        cosi=cos(i),
                        cosB=cos(B),
                        sinB=sin(B),
                        t=sini*cosj2*cosA-sinj* sinA;
                int x=40+30*mess*(cosi*cosj2*cosB-t*sinB),
                        y= 12+15*mess*(cosi*cosj2*sinB +t*cosB),
                        o=x+80*y,
                        N=8*((sinj*sinA-sini*cosj*cosA)*cosB-sini*cosj*sinA-sinj*cosA-cosi *cosj*sinB);

                if(22>y&&y>0&&x>0&&80>x&&mess>z[o]){
                    z[o]=mess;
                    b[o]=".,-~:;=!*#$@"[N>0? N:0];
                }
            }
        }
        printf("[d");
        for(k=0; screen_width>=k; k++)
            putchar(k%80?b[k]:10);
        A+=0.04;
        B+= 0.02;
    }












    // ------------
    // // Donut result(*this);
    // int screen_width = 1760;
    //
    // // variable meanings:
    // // A - rotation about x-axis
    // // B - rotation about z-axis
    // float A = 0, B = 0;
    //
    // // theta - angle around center point by radius to create circle in xy plane
    // // phi - rotating it around the y-axis to create the taurus
    // float theta_spacing = 0.07, phi_spacing = 0.02;
    //
    // for ( ; ; ) {
    //     // zbuffer - z cord of everything drawn
    //     // output - character at all indexes
    //     float zbuffer[screen_width];
    //     char output[screen_width];
    //
    //     // rotating theta by 2pi to create a full circle
    //     // rotating phi by 2 pi to go all the way around the y-axis for full taurus
    //     for (float theta = 0; theta < (2 * M_PI); theta += theta_spacing) {
    //         // making the circle
    //         float cos_theta = cos(theta), sin_theta = sin(theta);
    //
    //         for (float phi = 0; phi < (2 * M_PI); phi += phi_spacing) {
    //             // rotating
    //             float cos_phi = cos(phi), sin_phi = sin(phi);
    //
    //             // rotation around the axises while moving
    //             float
    //                     sinA = sin(A),
    //                     cosA = cos(A),
    //                     sinB = sin(B),
    //                     cosB = cos(B);
    //
    //             // wtf is this shit
    //             float cosj2 = cos_theta + 2;
    //             float
    //                     mess =
    //                     1 / (sin_phi * cosj2 * sinA + sin_theta * cosA + 5);
    //             float t = sin_phi * cosj2 * cosA - sin_theta * sinA;
    //
    //             int x = 40 + 30 * mess * (cos_phi * cosj2 * cosB - t * sinB),
    //                     y =
    //                     12 + 15 * mess * (cos_phi * cosj2 * sinB + t * cosB),
    //                     o = x + 80 * y,
    //                     N = 8 * ((sin_theta * sinA - sin_phi * cos_theta * cosA)
    //                              * cosB - sin_phi * cos_theta * sinA -
    //                              sin_theta * cosA - cos_phi
    //                                                 * cos_theta * sinB);
    //             if (22 > y && y > 0 && x > 0 && 80 > x && mess > zbuffer[o]) {
    //                 zbuffer[o] = mess;
    //                 output[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
    //             }
    //         }
    //     }
    //
    //     printf("[d");
    //     for (int k = 0; 1761 > k; k++)
    //         putchar(k % 80 ? output[k] : 10);
    //     A += 0.04;
    //     B += 0.02;
    // }

    //
    // result.center.x += dt * velocity.width;
    // result.center.y += dt * velocity.height;







    // int screen_width = 1760;
    // float A=0, B=0, i, j, z[screen_width];
    // char b[screen_width];
    // printf("[2J");
    // for( ; ; ) {
    //     memset(b,32,screen_width);
    //     memset(z,0,7040);
    //     for(j=0; 6.28>j; j+=0.07) {
    //         for(i=0; 6.28 >i; i+=0.02) {
    //             float sini=sin(i),
    //                     cosj=cos(j),
    //                     sinA=sin(A),
    //                     sinj=sin(j),
    //                     cosA=cos(A),
    //                     cosj2=cosj+2,
    //                     mess=1/(sini*cosj2*sinA+sinj*cosA+5),
    //                     cosi=cos(i),
    //                     cosB=cos(B),
    //                     sinB=sin(B),
    //                     t=sini*cosj2*cosA-sinj* sinA;
    //             int x=40+30*mess*(cosi*cosj2*cosB-t*sinB),
    //                     y= 12+15*mess*(cosi*cosj2*sinB +t*cosB),
    //                     o=x+80*y,
    //                     N=8*((sinj*sinA-sini*cosj*cosA)*cosB-sini*cosj*sinA-sinj*cosA-cosi *cosj*sinB);
    //             if(22>y&&y>0&&x>0&&80>x&&mess>z[o]){
    //                 z[o]=mess;
    //                 b[o]=".,-~:;=!*#$@"[N>0? N:0];
    //             }
    //         }
    //     }
    //     printf("[d");
    //     for(k=0; screen_width>=k; k++)
    //         putchar(k%80?b[k]:10);
    //     A+=0.04;
    //     B+= 0.02;
    // }



    // return result;
}

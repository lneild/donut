#include "donut.hxx"

#include <stdio.h>
// #include <string.h>
// #include <time.h>
// #include <cmath>


int main(){

    // Donut donut;
    //
    // donut.rotate();

    int k;
    int screen_width = 1760;

    // variable meanings:
    // A - rotation about x-axis
    // B - rotation about z-axis
    float A = 0, B = 0;

    // theta - angle around center point by radius to create circle in xy plane
    // phi - rotating it around the y-axis to create the taurus
    float theta_spacing = 0.07, phi_spacing = 0.02;

    // z - z cord of everything drawn
    // output - character at all indexes
    float z[screen_width];
    char output[screen_width];

    printf("[2J");

    for( ; ; ) {
        // compute sin/cos of A and B
        float cosA = cos(A), sinA = sin(A);
        float cosB = cos(B), sinB = sin(B);

        // delay(30);//delay can be changed as per requirement to speed up the trasitions

        int milli_seconds = 1000 * 30;
        clock_t start_time = clock();
        while (clock() < start_time + milli_seconds)
            ;

        memset(output,32,screen_width);
        memset(z,0,7040);

        // rotating phi by 2 pi to go all the way around the y-axis for full
        // taurus

        // theta goes around the center to create a circle
        for (float theta=0; theta < 2*M_PI; theta+=theta_spacing) {
            // precompute sines and cosines of theta
            float cos_theta = cos(theta), sin_theta = sin(theta);

            for (float phi=0; phi <= 2*M_PI; phi+=phi_spacing) {
                // precompute sines and cosines of phi
                float cos_phi = cos(phi), sin_phi = sin(phi);

                float cos_theta2=cos_theta+2,
                        mess=1/(sin_phi*cos_theta2*sinA+sin_theta*cosA+5),
                        t=sin_phi*cos_theta2*cosA-sin_theta* sinA;
                int x=40+30*mess*(cos_phi*cos_theta2*cosB-t*sinB),
                        y= 12+15*mess*(cos_phi*cos_theta2*sinB +t*cosB),
                        o=x+80*y,
                        N=8*((sin_theta*sinA-sin_phi*cos_theta*cosA)
                                *cosB-sin_phi*cos_theta*sinA-sin_theta*cosA-cos_phi
                                *cos_theta*sinB);

                if(22 > y&&y>0&&x>0&&80>x&&mess>z[o]){
                    z[o]=mess;
                    output[o]=".,-~:;=!*#$@"[N>0 ? N:0];
                }
            }
        }
        printf("[d");
        for(k=0; screen_width>=k; k++)
            putchar(k%80 ? output[k]:10);

        //advancing in the rotation
        A += 0.04;
        B += 0.02;
    }

return 0;

}


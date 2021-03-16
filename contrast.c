// According to https://www.w3.org/WAI/GL/wiki/Relative_luminance

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "colors.c"

// Declarations
double calLum(double in_r, double in_g, double in_b);
double defRGB(double in);
double calCon(double color1, double color2);

// Main just to prove the concept
int main(int argc, char *argv[])
{

    if (argc != 7)
    {
        if (argc == 4)
        {
            printf("Contrast needs 2 RGB colours\n");
        }
        printf("Usage: ./contrast 255 255 255 0 0 0\n");
        return 1;
    }
    // Capture and convert CLA to doubles
    double a, b, c, a2, b2, c2;
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    a2 = atof(argv[4]);
    b2 = atof(argv[5]);
    c2 = atof(argv[6]);

    double color1 = calLum(a, b, c);
    double color2 = calLum(a2, b2, c2);

    double ratio = calCon(color1, color2);
    // Prints to 12 Decimal Places
    printf("%.2f", ratio);
    printf(":1\n");
    if (ratio < 4.5)
    {
        printf("Contrast Fail");
    }
    else if (ratio > 4.4 && ratio < 7)
    {
        printf("Meets Minimum Contrast Ratio\n");
    }
    else if (ratio >= 7)
    {
        printf("Meets Reccomended Contrast Ratio\n");
    }
}

double calCon(double color1, double color2)
{
    double contrast;

    // if 1 is bigger (and therefore lighter) than 2
    if (color1 > color2)
    {
        //  (L1 + 0.05) / (L2 + 0.05)
        contrast = (color1 + 0.05) / (color2 + 0.05);
    }
    // else if 2 is bigger (and therefore lighter) than 1
    else
    {
        //  (L2 + 0.05) / (L1 + 0.05)
        contrast = (color2 + 0.05) / (color1 + 0.05);
    }
    return contrast;
}

double calLum(double in_r, double in_g, double in_b)
{
    // Define RsRGB, GsRGB, BsRGB       *8bit/255*
    double RsRGB = in_r / 255;
    double GsRGB = in_g / 255;
    double BsRGB = in_b / 255;
    // Define R, G & B
    double r = defRGB(RsRGB);
    double g = defRGB(GsRGB);
    double b = defRGB(BsRGB);
    //  L = (0.2126 * R) + (0.7152 * G) + (0.0722 * B)
    r = 0.2126 * r;
    g = 0.7152 * g;
    b = 0.0722 * b;
    // Calculate L
    double l = r + b + g;
    // Return L (Luminance)
    return l;
}

// if RsRGB <= 0.03928 then R = RsRGB/12.92 else R = ((RsRGB+0.055)/1.055) ^ 2.4
// if GsRGB <= 0.03928 then G = GsRGB/12.92 else G = ((GsRGB+0.055)/1.055) ^ 2.4
// if BsRGB <= 0.03928 then B = BsRGB/12.92 else B = ((BsRGB+0.055)/1.055) ^ 2.4
double defRGB(double in)
{
    double out;

    if (in <= 0.03928)
    {
        out = in / 12.92;
    }
    else
    {
        // ((in + 0.055) / 1.055) ^ 2.4
        out = in + 0.055;
        out = out / 1.055;
        out = pow(out, 2.4);
    }
    return out;
}

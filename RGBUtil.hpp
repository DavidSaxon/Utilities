/*********************************************\
| Utilities functions relating to RGB colours |
\*********************************************/
#ifndef _UTILITIES_RGBUTIL_H_
#   define _UTILITIES_RGBUTIL_H_

namespace util { namespace rgb {

    //TYPEDEFS
    typedef unsigned char byte;

    //FUNCTIONS
    /*multiplies two rgb colour integers together by using p as the percentage
    of the second colour to multiply into the first*/
    unsigned multiplyRGB(unsigned a, unsigned b, float p) {

        //break the colours down into their 1 byte parts
        byte ar = static_cast<byte>(a >> 16);
        byte ag = static_cast<byte>(a >> 8);
        byte ab = static_cast<byte>(a);
        byte br = static_cast<byte>(b >> 16);
        byte bg = static_cast<byte>(b >> 8);
        byte bb = static_cast<byte>(b);

        //multiply the rgb values
        ar = static_cast<byte>((ar*(1.0-p))+(br*p));
        ag = static_cast<byte>((ag*(1.0-p))+(bg*p));
        ab = static_cast<byte>((ab*(1.0-p))+(bb*p));

        //join back as an integer
        unsigned result = 0;
        result |= (ar << 16);
        result |= (ag << 8);
        result |=  ab;

        return result;
    }

    /*Decompose an integer into its rgb parts*/
    void decomposeRGB(unsigned i, byte* _rgb) {

        _rgb[0] = static_cast<byte>(i >> 16);
        _rgb[1] = static_cast<byte>(i >> 8);
        _rgb[2] = static_cast<byte>(i);
    }

    /*Compares the equality of the 2 rgb colours, if the returned value is
    zero then the colours are equal, else the higher the returned number the
    less equal the colours are*/
    unsigned equalsRGB(unsigned a, unsigned b) {

        //decompose the colours
        byte rgb1[3] = {0};
        byte rgb2[3] = {0};
        decomposeRGB(a, rgb1);
        decomposeRGB(b, rgb2);

        //subtract the values of colour1 from colour2
        int rd = static_cast<int>(rgb2[0])-static_cast<int>(rgb1[0]);
        int gr = static_cast<int>(rgb2[1])-static_cast<int>(rgb1[1]);
        int bl = static_cast<int>(rgb2[2])-static_cast<int>(rgb1[2]);

        return abs(rd)+abs(gr)+abs(bl);
    }

}}

#endif
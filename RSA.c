#include <stdio.h>
#include <math.h>

// Returns the gratest comon denominator of x and y
int gcd(int x, int y)
{
    int temp;
    while (1)
    {
        temp = x%y;
        if (temp == 0)
          return y;
        x = y;
        y = temp;
    }
}

// Code to demonstrate RSA algorithm
int main()
{
    // Two random prime numbers
    int p = 3;
    int q = 7;
  
    // First part of public key
    int n = p*q;
    // Finding other part of public key (e stands for encrypt)
    int e = 2;
    int theta = (p-1)*(q-1);
    while (e < theta)
    {
        // e must be co-prime to theta and smaller than theta
        if (gcd(e, theta)==1)
            break;
        else
            e++;
    }
  
    // Private key (d stands for decrypt) choosing d such that it satisfies d*e = 1 + k * theta
    int k = 2;  // A constant value
    int d = (1 + (k*theta))/e;
  
    // Message to be encrypted
    int msg = 33;
    printf("Message data = %d", msg);
  
    // Encryption c = (msg ^ e) % n
    int c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %d", c);
  
    // Decryption m = (c ^ d) % n
    int m = pow(c, d);
    m = fmod(m, n);
    printf("\nOriginal Message Sent = %d", m);
  
    return 0;
}
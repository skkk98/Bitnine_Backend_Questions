
#include <stdio.h>
#include <stdlib.h>

int fib1(int n){
    //using rescursion
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else return fib1(n-3) + fib1(n-2);
}

int fib2(int n){
    //using dp array
    int F[n];
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else{
        F[0]=0,F[1]=1;F[2]=2;
        int i=3;
        while(i<=n){
            F[i] = F[i-3]+F[i-2];
            i++;
        }
    }
    return F[n];
}

int fib3(int n){
    // only 3 variables
    int result = 0;
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else{
        int first = 0;
        int second = 1;
        int third = 2;
        int i = 3;
        while(i<=n){
            result = first + second;
            first = second;
            second = third;
            third = result;
            i++;
        }
    }
    return result;
}

// int fib4(int n){
//     //using formula [((root(5)+1)/2)^n]/root(5) and then round it off
//     double prefix_calc = (sqrt(5)+1)/2;
//     return round(pow(prefix_calc, n)/sqrt(5));
// }

int main()
{
    //F(n) = F(n-3)+F(n-2);
    
    //1st Way - Using Recursion method to calculate this custom Fibonacci number
    //Time Complexity O(2^n), Space Complexity O(n), n is the nth Fibonacci num.
    //Disadvantage - Time is Exponential so it won't return answers immediately
    
    //2nd Way - Using DP array to store previous results and calculate accordingly
    //Time Complexity O(n), Space Complexity O(n), n is the nth Fibonacci num.
    //Time is linear.
    
    //3rd Way - Using DP but only storing three previous calculated F(). and 
    //updating in every iteration
    //Time Complexity O(n), Space Complexity O(1), n is the nth Fibonacci num.
    //Time is linear but advantage is that we aren't using any space.
    
    printf("1st way, Fib(6) - %d\n", fib1(6));
    printf("2nd way, Fib(6) - %d\n", fib2(6));
    printf("3rd way, Fib(6) - %d\n", fib3(6));

    return 0;
}

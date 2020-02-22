//
// Created by Александр Волков on 08.11.18.
//

#ifndef CACHE_LAB_CACHE_H
#define CACHE_LAB_CACHE_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <chrono>


struct A {
    int id;
    std::string name_tour;
    long long time ;
    unsigned int buffer ;
};

class Cache {
    std::vector <A> f ;
    void direct_tour_arr (const int * arr , unsigned int capacity ){
        unsigned int a;
        for (unsigned int i = 0 ; i<capacity ; ++i){
            a = arr[i];
        }
    }
    void reverse_tour_arr (const int * arr , unsigned int capacity ){
        unsigned int a;
        for (unsigned int i = capacity-1 ; i != 0 ; --i){
            a = arr[i];
        }
    }
    void random_tour_arr (int * arr , unsigned int capacity ){
        unsigned int a;
        unsigned int b;
        for (unsigned int i = 0; i<capacity ; ++i){
            a=rand()%capacity;
            std::swap(arr[a],arr[capacity-1]);
            capacity--;
        }
    }
public:
    void run(){
        unsigned  capacity = 4096;
        int j = 1;

        while ( capacity != 1179648 ) {
            int *arr1 = new int [capacity];
            srand(time(NULL));
            for (unsigned int i =0 ; i < capacity ; ++i){
                arr1[i]=rand();
            }

            auto start_time = std::chrono::high_resolution_clock::now();
            for (unsigned int i =0 ; i < 1000 ; ++i){
                direct_tour_arr(arr1,capacity);
            }
            auto finish_time = std::chrono::high_resolution_clock::now();
            auto ans1=std::chrono::duration_cast<std::chrono::milliseconds>  (finish_time - start_time) ;
            A exp1 = { j , "direct" , ans1.count() , capacity };
            f.push_back(exp1);
            delete[] arr1;


            int *arr2 = new int [capacity];
            srand(time(NULL));
            for (unsigned int i =0 ; i < capacity ; ++i){
                arr2[i]=rand();
            }
            start_time = std::chrono::high_resolution_clock::now();
            for (unsigned int i =0 ; i < 1000 ; ++i){
                reverse_tour_arr(arr2,capacity);
            }
            finish_time = std::chrono::high_resolution_clock::now();
            auto ans2=std::chrono::duration_cast<std::chrono::milliseconds> (finish_time - start_time) ;
            A exp2 = { j , "reverse" , ans2.count() , capacity };
            f.push_back(exp2);
            delete[] arr2;


            int *arr3 = new int [capacity];
            srand(time(NULL));
            for (unsigned int i =0 ; i < capacity ; ++i){
                arr3[i]=rand();
            }
            start_time = std::chrono::high_resolution_clock::now();
            for (unsigned int i =0 ; i < 1000 ; ++i){
                random_tour_arr(arr3,capacity);
            }
            finish_time = std::chrono::high_resolution_clock::now();
            auto ans3=std::chrono::duration_cast<std::chrono::milliseconds>  (finish_time - start_time) ;
            A exp3 = { j , "random" , ans3.count() , capacity };
            f.push_back(exp3);
            delete[] arr3;

            capacity = capacity *2;
            if (capacity > 1179648 )  {
                capacity = 1179648;
            }
            show();
            ++j;
        }
    }
    void show() {
        for (unsigned int i = 0; i < f.size(); ++i) {
            std::cout << "number of experiment = " << f[i].id << std::endl;
            std::cout << "name of experiment : " << f[i].name_tour << std::endl;
            std::cout << "time  of experiment = " << f[i].time << std::endl;
            std::cout << "buffer of experiment = " << f[i].buffer << std::endl;
            std::cout << std::endl;
        }
    }
};

#endif //CACHE_LAB_CACHE_H

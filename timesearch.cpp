void TimeSearch() {
  int a[1001], n[20];
   const long r[20] = {300000, 300000, 200000, 200000, 100000, 100000,
  100000, 80000, 80000, 50000, 50000, 25000, 15000, 15000, 10000, 7500, 7000,
  6000, 5000, 5000};
  
  for (int j = 1; j <= 1000; j++) // initialize a
    a[j] = j;
  
  for (j = 0; j < 10; j++)  {// values of n
    n[j] = 10 * j ; n[j+10] = 100 * (j+1);
  }
  
  cout <<  "   n   totalTime   runTime" << endl;
  
  for(j = 0; j < 20; j++)  { // obtain computing times
    long start, stop ;
    time(start); // start timer
    for (long b = 1; b <= r[j]; b++)
      int k = SequentialSearch(a, n[j], 0); // unsuccessful search
    time(stop) ; // stop timer
    long totalTime = stop - start ;
    float runTime = (float) (totalTime)/(float)(r[j]) ;
    cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl;
  }
  cout << "Times are in hundredths of a second." << endl;
}

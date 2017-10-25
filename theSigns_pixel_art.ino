   cntr++;                                 //Minecraft
   if (cntr>33) cntr=0;
   color=2;
   drawPixel(1+cntr,1);
   color=7;
   drawPixel(1+cntr,2);
   color=2;
   drawPixel(1+cntr,3);
   drawPixel(1+cntr,4);
   drawPixel(1+cntr,5);
   drawPixel(1+cntr,6);
   drawPixel(1+cntr,7);
   color=7;
   drawPixel(1+cntr,8);
    Transfer();
   delay(105);
   vClear();
   /*
   0-black
   1-red
   2-green
   3-white yellow
   4-ocean blue
   5-violet
   6-sky blue
   7-white pearl
   8-
   9- white red
   10-green
   11-white yellow
   etc
   */
   
   cntr2++;      //Pacman
   if (cntr2>43) cntr2=0;
   color=6;
   drawPixel(1+cntr2,1);
   drawPixel(1+cntr2,2);
   drawPixel(1+cntr2,3);
   drawPixel(1+cntr2,4);
   drawPixel(1+cntr2,5);
   drawPixel(1+cntr2,6);
   color=6;
   drawPixel(2+cntr2,2);
   drawPixel(2+cntr2,3);
   drawPixel(2+cntr2,4);
   drawPixel(2+cntr2,5);
   drawPixel(2+cntr2,6);
   drawPixel(2+cntr2,7);
   //color=8;
   //drawPixel(2+cntr2,5); 
   color=6;
   drawPixel(3+cntr2,1);
   drawPixel(3+cntr2,2);
   drawPixel(3+cntr2,3);
   drawPixel(3+cntr2,4);
   color=8;
   drawPixel(3+cntr2,5);
   drawPixel(3+cntr2,6);
   color=6;
   drawPixel(3+cntr2,7);
   drawPixel(3+cntr2,8);
   color=6;
   drawPixel(4+cntr2,2);
   drawPixel(4+cntr2,3);
   drawPixel(4+cntr2,4);
   color=8;
   drawPixel(4+cntr2,6);
   color=4;
   drawPixel(4+cntr2,5);
   color=6;
   drawPixel(4+cntr2,7);
   drawPixel(4+cntr2,8);
   color=6;
   drawPixel(5+cntr2,2);
   drawPixel(5+cntr2,3);
   drawPixel(5+cntr2,4);
   drawPixel(5+cntr2,5);
   drawPixel(5+cntr2,6);
   drawPixel(5+cntr2,7);
   drawPixel(5+cntr2,8);
   color=6;
   drawPixel(6+cntr2,1);
   drawPixel(6+cntr2,2);
   drawPixel(6+cntr2,3);
   drawPixel(6+cntr2,4);
   drawPixel(6+cntr2,5);
   drawPixel(6+cntr2,6);
   drawPixel(6+cntr2,7);
   drawPixel(6+cntr2,8);
   //color=8;
   //drawPixel(6+cntr2,5); 
   color=6;
   drawPixel(7+cntr2,2);
   drawPixel(7+cntr2,3);
   drawPixel(7+cntr2,4);
   color=8;
   drawPixel(7+cntr2,5);
   drawPixel(7+cntr2,6);
   color=6;
   drawPixel(7+cntr2,7);
   color=6;
   drawPixel(8+cntr2,1);
   drawPixel(8+cntr2,2);
   drawPixel(8+cntr2,3);
   drawPixel(8+cntr2,4);
   color=8;
   drawPixel(8+cntr2,6);
   color=4;
   drawPixel(8+cntr2,5);
   
   Transfer();
   delay(105);
   vClear();
   
   cntr3++;                               //draw pacman
   color=3;
   if (cntr3>33) cntr3=0;
   drawCircle(1+cntr3,5,3);
   drawCircle(1+cntr3,4,3);
   drawCircle(1+cntr3,3,2);
   drawCircle(1+cntr3,2,1);
   color=8;
   drawLine(1+cntr3,4, 6+cntr3,4);
   drawLine(1+cntr3,5, 6+cntr3,5);
   color=3;
   drawCircle(2+cntr3,2,1);
   drawCircle(2+cntr3,5,1);
   drawCircle(1+cntr3,5,1);
   drawCircle(1+cntr3,9,1);
   drawLine(0+cntr3,2, 0+cntr3,7);
   drawLine(-1+cntr3,3, -1+cntr3,6);
   
   Transfer();
   delay(105);
   vClear();
   
   cntr4++;      //Pacman
   if (cntr4>43) cntr4=0;
   color=9;
   drawPixel(1+cntr4,1);
   drawPixel(1+cntr4,2);
   drawPixel(1+cntr4,3);
   drawPixel(1+cntr4,4);
   drawPixel(1+cntr4,5);
   drawPixel(1+cntr4,6);
   color=9;
   drawPixel(2+cntr4,2);
   drawPixel(2+cntr4,3);
   drawPixel(2+cntr4,4);
   drawPixel(2+cntr4,5);
   drawPixel(2+cntr4,6);
   drawPixel(2+cntr4,7);
   //color=8;
   //drawPixel(2+cntr2,5); 
   color=9;
   drawPixel(3+cntr4,1);
   drawPixel(3+cntr4,2);
   drawPixel(3+cntr4,3);
   drawPixel(3+cntr4,4);
   color=8;
   drawPixel(3+cntr4,5);
   drawPixel(3+cntr4,6);
   color=9;
   drawPixel(3+cntr4,7);
   drawPixel(3+cntr4,8);
   color=9;
   drawPixel(4+cntr4,2);
   drawPixel(4+cntr4,3);
   drawPixel(4+cntr4,4);
   color=8;
   drawPixel(4+cntr4,6);
   color=4;
   drawPixel(4+cntr4,5);
   color=9;
   drawPixel(4+cntr4,7);
   drawPixel(4+cntr4,8);
   color=9;
   drawPixel(5+cntr4,2);
   drawPixel(5+cntr4,3);
   drawPixel(5+cntr4,4);
   drawPixel(5+cntr4,5);
   drawPixel(5+cntr4,6);
   drawPixel(5+cntr4,7);
   drawPixel(5+cntr4,8);
   color=9;
   drawPixel(6+cntr4,1);
   drawPixel(6+cntr4,2);
   drawPixel(6+cntr4,3);
   drawPixel(6+cntr4,4);
   drawPixel(6+cntr4,5);
   drawPixel(6+cntr4,6);
   drawPixel(6+cntr4,7);
   drawPixel(6+cntr4,8);
   //color=8;
   //drawPixel(6+cntr2,5); 
   color=9;
   drawPixel(7+cntr4,2);
   drawPixel(7+cntr4,3);
   drawPixel(7+cntr4,4);
   color=8;
   drawPixel(7+cntr4,5);
   drawPixel(7+cntr4,6);
   color=9;
   drawPixel(7+cntr4,7);
   color=9;
   drawPixel(8+cntr4,1);
   drawPixel(8+cntr4,2);
   drawPixel(8+cntr4,3);
   drawPixel(8+cntr4,4);
   color=8;
   drawPixel(8+cntr4,6);
   color=4;
   drawPixel(8+cntr4,5);
   
   Transfer();
   delay(105);
   vClear();
   
   
   cntr5++;      //Heart
   if (cntr5>58) cntr5=0;
   color=1;
   drawPixel(1+cntr5,4);
   drawPixel(1+cntr5,5);
   drawPixel(1+cntr5,6);
   drawPixel(1+cntr5,7);
   drawPixel(2+cntr5,3);
   drawPixel(2+cntr5,4);
   drawPixel(2+cntr5,5);
   drawPixel(2+cntr5,6);
   drawPixel(2+cntr5,7);
   drawPixel(2+cntr5,8);
   drawPixel(3+cntr5,2);
   drawPixel(3+cntr5,3);
   drawPixel(3+cntr5,4);
   drawPixel(3+cntr5,5);
   drawPixel(3+cntr5,6);
   drawPixel(3+cntr5,7);
   drawPixel(3+cntr5,8);
   drawPixel(4+cntr5,1);
   drawPixel(4+cntr5,2);
   drawPixel(4+cntr5,3);
   drawPixel(4+cntr5,4);
   drawPixel(4+cntr5,5);
   drawPixel(4+cntr5,6);
   drawPixel(4+cntr5,7);
   drawPixel(5+cntr5,1);
   drawPixel(5+cntr5,2);
   drawPixel(5+cntr5,3);
   drawPixel(5+cntr5,4);
   drawPixel(5+cntr5,5);
   drawPixel(5+cntr5,6);
   drawPixel(5+cntr5,7);
   drawPixel(6+cntr5,2);
   drawPixel(6+cntr5,3);
   drawPixel(6+cntr5,4);
   drawPixel(6+cntr5,5);
   color=7;
   drawPixel(6+cntr5,6);
   color=1;
   drawPixel(6+cntr5,7);
   drawPixel(6+cntr5,8);
   drawPixel(2+cntr5,3);
   drawPixel(7+cntr5,4);
   drawPixel(7+cntr5,5);
   color=7;
   drawPixel(7+cntr5,6);
   drawPixel(7+cntr5,7);
   color=1;
   drawPixel(7+cntr5,8);
   drawPixel(8+cntr5,4);
   drawPixel(8+cntr5,5);
   drawPixel(8+cntr5,6);
   drawPixel(8+cntr5,7);
   
 

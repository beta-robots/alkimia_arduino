// CLEAR ALL **********************************************************************
xdel(winsid());
clear;

// PARAMS **********************************************************************
rpmin = 0; //min potentiometer resistance [ohm]
rpmax = 10000; //max potentiometer resistance [ohm]
vcc = 5; //power voltage
rd = [10:10:20000]; //resistor at divider

//voltage divider range function
vdmin = vcc*rpmin./(rpmin+2*rd);
vdmax = vcc*rpmax./(rpmax+2*rd);
vdrange = vdmax - vdmin;

//plot
fig1 = figure();
fig1.background = 8;
plot(rd,vdrange,"blue");
plot(rd,vdmin,"red");
plot(rd,vdmax,"green");
plot(rd,3.3,"black");
ah = gca();
ah.auto_scale = "off";
ah.tight_limits = "on";
ah.data_bounds = [0,0;20000,5];
ah.x_label.text = "$R_d\ [\Omega]$";
ah.x_label.font_size = 4;
ah.y_label.text = "$[V_d]$";
ah.y_label.font_size = 4;
lh =legend(["$\Delta V_d$";"$V_{d,min}$";"$V_{d,max}$"],1);
lh.font_size = 3;
title("$Voltage\ divider,\ potentiometer\ 10K \Omega$");
ah.title.font_size = 4;


//Declare your Nextion objects , pageid, component id., component name

NexButton b0 = NexButton(1, 2, "b0");
NexButton b1 = NexButton(1, 3, "b1");
NexButton b2 = NexButton(1, 4, "b2");
NexButton b3 = NexButton(1, 5, "b3");
NexButton b4 = NexButton(1, 14, "b4");

NexText t0 = NexText(1, 6, "t0");
NexText t1 = NexText(1, 7, "t1");
NexText t2 = NexText(1, 8, "t2");
NexText t3 = NexText(1, 9, "t3");
NexText t4 = NexText(1, 10, "t4");
NexText t5 = NexText(1, 11, "t5");
NexText t6 = NexText(1, 13, "t6");
NexNumber n0 = NexNumber(1, 15, "n0");
NexPage p0 = NexPage(0, 0, "Home");
NexPage p1 = NexPage(1, 0, "Mainpage");

//Register a button object to the touch event list

NexTouch *nex_listen_list[] = {
  &b0,
  &b1,
  &b2,
  &b3,
  &b4,
  NULL
};

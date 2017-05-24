XL2
H 1 areas 3 global symbols
M screen
S .__.ABS. Def0000
S writevdpreg1 Ref0000
A _CODE size 8 flags 0 addr 0
S _screen_off_disable_nmi Def0000
T 00 00
R 00 00 00 00
T 00 00 3A C4 73 E6 9F C3 00 00
R 00 00 00 00 02 08 01 00

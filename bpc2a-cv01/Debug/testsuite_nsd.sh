#! /bin/sh
# testsuite_nsd v1.1(linux), Pety & Milos, 2015
# $Id: testsuite_nsd.sh 125 2015-07-03 16:18:28Z petyovsky $

# clear

# Nazev souboru, pripony vstupniho vystupniho a vzoroveho souboru
# Navratova hodnota programu,
./testcase ./mainsd delitel_05 2
# if [ $? -ne 0 ] ; then echo "Chyba"; fi
./testcase ./mainsd delitel_04 1
./testcase ./mainsd delitel_01 0
./testcase ./mainsd delitel_02 0
./testcase ./mainsd delitel_03 0

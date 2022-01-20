from scripts.gpsGoldCode import PRN

f_prn = 10.23e6 / 10  # chipping frequency

goldCode = (PRN(24))
sat_24 = [-1 if x==0 else x for x in goldCode]
#prn = lambda x: sat_24[int(x*f_prn)%1023]
#chart.plot('GPS Sat 24 PRN Code', tend=1023/f_prn, sr=1.0e-7).signal(prn, lw=0.7).show()

print(goldCode)
print(sat_24)

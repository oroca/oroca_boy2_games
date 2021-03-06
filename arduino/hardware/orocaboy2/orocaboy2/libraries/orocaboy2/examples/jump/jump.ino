#define FPS   25

#define SECOND(_sec)       ((_sec)*FPS)
#define MINUTE(_min)       (SECOND(_min)*60)
#define HOUR(_hour)        (MINUTE((_hour)*60))

#define MM(_mm)             (CM(0.1f*(_mm)))
#define CM(_cm)             (M(0.01f*(_cm)))
#define  M(_m)              (_m)
#define KM(_km)             (M(1000.0f*(_km)))

// m/s
#define M_S(_speed)         (M(_speed) / SECOND(1.0f))
// km/h
#define KM_H(_speed)        (KM(_speed) / HOUR(1.0f))
// m/s^2
#define M_S2(_acc)          (M(_acc) / (SECOND(1.0f) * SECOND(1.0f)))




const uint16_t orocaboy_copyData[] = {24,24,4, 1, 0, 0, 0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xce79,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xfb0c,0xfb0c,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xce79,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xffff,0x861,0xffff,0xffff,0xf800,0xfb0c,0xff1c,0xff1c,0xfb0c,0xf800,0xffff,0xffff,0x861,0xffff,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0xf800,0xff1c,0xffff,0xffff,0xfeba,0xf800,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xf800,0xffff,0xffff,0xf800,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xf800,0xf800,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xf800,0xfb0c,0xfb0c,0xfb0c,0xfb0c,0xf800,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xf800,0xfb0c,0xfeba,0xfeba,0xfeba,0xfeba,0xfb0c,0xf800,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xfeba,0xffff,0xffff,0xfeba,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xce79,0xce79,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xce79,0xce79,0x861,0xffff,0x861,0xce79,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xce79,0x861,0x861,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xf800,0xf800,0xfb0c,0xfb0c,0xf800,0xf800,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xfb0c,0xfeba,0xfeba,0xfeba,0xfeba,0xfb0c,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xfb0c,0xfeba,0xfeba,0xffff,0xffff,0xfeba,0xfeba,0xfb0c,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0x861,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xf800,0xf800,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0x861,0xce79,0xffff,0xffff,0x861,0xffff,0xffff,0xf800,0xfb0c,0xfb0c,0xfb0c,0xfb0c,0xf800,0xffff,0xffff,0x861,0xffff,0xffff,0xce79,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xf800,0xfb0c,0xfeba,0xfeba,0xfeba,0xfeba,0xfb0c,0xf800,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xf800,0xfeba,0xffff,0xffff,0xfeba,0xf800,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0x861,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff};
Image orocaboy = Image(orocaboy_copyData);


float speed = 0.0;
float accel = 0.0f;

float x = gb.display.width()/2;
float y = gb.display.height()-orocaboy.height()*2;
int   dir = 1;
bool  start = false;

void setup() {
  // put your setup code here, to run once:
  gb.begin();  
}


void loop() {
  // put your main code here, to run repeatedly:
  static int   cnt = 0;
  static float sec = 0.0;
  
  if (gb.update())
  {
    gb.display.clear();
    gb.display.fill(Color::white);

    gb.display.setColor(Color::black);
    gb.display.println(speed);

    if (start == true)
    {
      if (dir > 0)
      {
        speed += accel;              
        y += speed*10.0f;
      }
      else
      {
        speed -= accel;      
        y -= speed*10.0f;        
      }

      if (y > gb.display.height()-orocaboy.height()*2)
      {
        y = gb.display.height()-orocaboy.height()*2;
        speed = speed * 0.5;
        accel = accel * 0.5;        
        dir = dir * -1;
      }
    }
    
    gb.display.println(y);

    if (gb.buttons.pressed(Button::a))
    {
      //x = gb.display.width()/2;
      y = gb.display.height()-orocaboy.height()*2;
      dir = -1;

      speed = M_S(15.1f);  // 처음속도(0m/s)
      accel = M_S2(15.0f); // 가속도 (2m/s^2)       
      start = true;
    }

    if (gb.buttons.repeat(Button::left,  1))
    {
      x -= M_S(15.1f) * 10;
    }
    if (gb.buttons.repeat(Button::right, 1))
    {
      x += M_S(15.1f) * 10;
    }
          
    gb.display.drawImage((uint16_t)x, y, orocaboy, orocaboy.width()*2, orocaboy.height()*2);    
    orocaboy.setFrame((cnt>>1)%4);        
    cnt++;
  }  
}

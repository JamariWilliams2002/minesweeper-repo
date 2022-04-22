using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClockLecture
{
    class Alarm
    {
        DateTime mAlarmTime;
        bool alarmOn;
        Alarm(DateTime alarmTime)
        {
            mAlarmTime = alarmTime;
            alarmOn = true;
            SetAlarm();
        }
        public void SetAlarm()
        {
            if (alarmOn)
            {

            }
        }
        public void SetAlarm(DateTime alarmTime)
        {
            mAlarmTime = alarmTime;
        }
        //public methods
        public void TurnOn()
        {
            alarmOn = true;
        }

        public void TurnOff()
        {
            alarmOn = false;
        }
    }
}

//object shouldt ake in time
//should be turned on and off
//
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClockLecture
{
    public class Alarm
    {
        public delegate void AlarmUpdate(DateTime time);
        public event AlarmUpdate AlarmUpdateHandler;

        //private fields
        DateTime mAlarmTime;
        bool alarmOn;
        public Alarm(DateTime alarmTime)
        {
            mAlarmTime = alarmTime;
            TurnOn();
        }
        //check to see if the alarm should fire
        public void CheckFire(DateTime time)
        {
            if (!alarmOn)
                return;

            if(time == mAlarmTime)
            {
                if(mAlarmTime > time)
                {
                    TurnOff();
                    Task.Run(() =>
                    {
                        for (int i = 0; i < 20; i++)
                        {
                            Console.Beep();
                        }
                    });
                }
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
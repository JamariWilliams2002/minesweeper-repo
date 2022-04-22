using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClockLecture
{
    public class Clock
    {
        public delegate void TimeUpdated(DateTime time);
        public event TimeUpdated TimeUpdatedHandler;
        public Clock()
        {
            Start();
        }
        private void Start()
        {
            //this function puts the task on a new thread on the cpu
            Task.Run(() =>
            {
                DateTime latestTime = DateTime.Now;
                while (true)
                {
                    DateTime now = DateTime.Now;

                    if (TimeUpdatedHandler != null)
                    {
                        if (((latestTime - now).TotalSeconds) >= 1)
                        {

                            latestTime = now;
                            TimeUpdatedHandler(now);
                        }
                    }
                }
            });
        }
    }
}
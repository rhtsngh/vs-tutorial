using Microsoft.Owin.Hosting;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.ServiceProcess;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Web.Http;
using System.Windows.Forms;
using WebApiOwin;

namespace WebApiOwinWinforms
{
    public partial class Form1 : Form
    {
        Thread thread;
        public static Form1 s_formInstance { get; set; }

        public Form1()
        {
            InitializeComponent();

            s_formInstance = this;

            string baseAddress = "http://localhost:1234/";
            WebApp.Start<Startup>(url: baseAddress);

        }

        public void SayHi(string name)
        {
            if (InvokeRequired) Invoke((MethodInvoker)delegate {
                SayHi(name);
            });
            else label1.Text = $"Hi {name}!";
        }
    }

}

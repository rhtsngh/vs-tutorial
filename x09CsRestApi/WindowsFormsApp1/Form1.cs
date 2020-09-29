using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using SimpleHttp;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            var response = await RestHelper.GetAll();
            Console.WriteLine(" - " + response);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Route.Add("/", (req, res, props) =>
            {
                res.AsText("Welcome to Simple Http Server!");
            });

            Route.Add("/users/{id}", (req, res, props) =>
            {
                res.AsText($"You requested user #{props["id"]}");
            }, "POST");

            Route.Add("/header", (req, res, props) =>
            {
                res.AsText($"Value of my-header is: {req.Headers["my-header"]}");
            });

            //HttpServer.ListenAsync(1337, CancellationToken.None, Route.OnHttpRequestAsync).Wait();
            Thread thread = new Thread(new ThreadStart(HttpServer.ListenAsync(1337, CancellationToken.None, Route.OnHttpRequestAsync).Wait));
            thread.Start();
        }
    }
}

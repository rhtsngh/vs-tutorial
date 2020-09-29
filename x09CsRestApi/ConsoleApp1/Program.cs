using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using SimpleHttp;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
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

            HttpServer.ListenAsync(1337, CancellationToken.None, Route.OnHttpRequestAsync).Wait();
        }
    }
}

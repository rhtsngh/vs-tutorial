using Microsoft.Owin.Hosting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;



namespace WebApiOwin
{
    // Sample source:
    // https://docs.microsoft.com/en-us/aspnet/web-api/overview/hosting-aspnet-web-api/use-owin-to-self-host-web-api
    class Program
    {
        static void Main(string[] args)
        {
            string baseAddress = "http://localhost:1234/";

            // Start OWIN host 
            //using (WebApp.Start<Startup>(url: baseAddress))
            //{
                WebApp.Start<Startup>(url: baseAddress);
                // Create HttpClient and make a request to api/values 
                HttpClient client = new HttpClient();

                var response = client.GetAsync(baseAddress + "api/values").Result;
                Console.WriteLine(response);
                Console.WriteLine(response.Content.ReadAsStringAsync().Result);

                response = client.GetAsync(baseAddress + "api/greetings").Result;
                Console.WriteLine(response);
                Console.WriteLine(response.Content.ReadAsStringAsync().Result);

                response = client.GetAsync(baseAddress + "api/connections").Result;
                Console.WriteLine(response);
                Console.WriteLine(response.Content.ReadAsStringAsync().Result);

                Console.ReadLine();
            //}
        }
    }
}

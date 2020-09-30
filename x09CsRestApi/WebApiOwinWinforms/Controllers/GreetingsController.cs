using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Http;
using WebApiOwin.Models;
using WebApiOwinWinforms;

namespace WebApiOwin.Controllers
{
    public class GreetingsController : ApiController
    {
        // GET api/greetings 
        public IEnumerable<string> Get([FromBody] MRequest body)
        {
            Form1.s_formInstance.SayHi("Minh");
            return new string[] { "Hi!" };
        }

        // GET api/values/5 
        public string Get(int id)
        {
            return $"Hi! {id}";
        }
    }
}

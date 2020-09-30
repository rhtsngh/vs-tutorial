using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Http;
using WebApiOwin.Models;

namespace WebApiOwin.Controllers
{
    public class GreetingsController : ApiController
    {
        // GET api/greetings 
        public IEnumerable<string> Get([FromBody] MRequest body)
        {
            return new string[] { "Hi!" };
        }

        // GET api/values/5 
        public string Get(int id)
        {
            return $"Hi! {id}";
        }
    }
}

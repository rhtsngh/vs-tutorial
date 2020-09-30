using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Http;
using WebApiOwin.Models;

namespace WebApiOwin.Controllers
{
    public class ConnectionsController : ApiController
    {
        // GET api/connections 
        public IEnumerable<string> Get()
        {
            return new string[] { "true" };
        }

        // POST api/connections 
        public string Post([FromBody] MRequest request)
        {
            if (request.state == MState.on.ToString()) return "ok";
            else return "no";
        }
    }
}

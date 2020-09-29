using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace x03Beginning3.Controllers
{
    public class HelloController : ApiController
    {
        public IEnumerable<string> Get()
        {
            return new string[] { "Hello", "World" };
        }
    }
}

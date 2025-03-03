
RabbitMQ in 3 mins -

RabbitMQ is a popular message broker tool that transfers data between services. It accepts messages from producers and delivers them to consumers. The publish-subscribe mechanism enables an application to announce events to multiple consumers asynchronously.


The Problem it solves -

In distributed applications, there are times when some services of the application need to interact with each other in case of an event happening. In traditional systems, this was achieved using synchronous communication such as REST. This kind of communication uses a request-response system where one service(sender) initiates a call to the other service(consumer) and then waits for that service to return a response. This causes some problems. 
One, the service that initiated this call, now has to wait for the response and till then, this service is blocked from doing other operations. This can even affect user experience in some cases.
Two, senders and receivers are now tightly coupled.
Three, in the case of a microservice architecture, where there are numerous services, the number of these calls can become really large.


How RabbitMQ solves the problem -

RabbitMQ solves this problem by providing an asynchronous publish-subscribe communication system. In such a system, rather than allowing two applications/services to communicate with each other directly, an additional component such as a queue is introduced as an intermediary. This additional component is known as the Message Broker. Services can read/write messages from/to this broker per their availability. This kind of communication system has many benefits -

1. The sender no longer remains blocked from executing other tasks as it no longer waits for a response.
2. It aids in decoupling applications. Since applications interact by employing a Message Broker, they can communicate without directly connecting to each other. 
3. The number of calls is significantly reduced, as now the senders can directly get the response from the message brokers.
4. It also provides the functionality of queueing messages which is immensely helpful.

However, the system is now immensely dependent on the Message Broker. If the Message Broker goes down, the system is compromised. Although, this can be resolved by deploying a cluster of Message Brokers.



NGINX in 3 mins -

NGINX has become a popular and powerful web tool in a short period of time. Using it as a web server, we can make sure that our page load time is reduced as it is extremely fast. It can handle a large number of connections without compromising performance as it still maintains its speed. Initially brought in as a powerful web server, it has evolved and now also serves as a reverse proxy, load balancer, cache server, and a lot more. NGINX is easily highly scalable, which ensures that its service grows along with its clients’ traffic.
What makes NGINX a popular and powerful tool is its non-threaded and event-driven architecture. This ensures the processing of multiple requests at the same time.

Event-driven architecture?
This kind of asynchronous architecture is very different than the traditional process-driven architecture. Earlier, each client request was handled as an individual thread, which became complicated to handle the increasing number of connections. This leads to a delayed response, and the web server slows down. Switching between different threads requires CPU utilization along with extended memory usage and CPU time, which in turn impacts the performance of the website.

To avoid such kinds of complications Nginx uses the advanced event-based architecture. It uses event notification heavily and that leads to putting the specific tasks to specific processors. Because of this, processors run efficiently. It does not allocate a process to a particular connection, but it creates a process pool that can be easily shared among multiple connections within the network. Whenever a request is made, a resource will be allocated to the process, resulting in better resource utilization that can easily handle extensive connections. There are a limited number of single-thread processors called workers. Each worker can process 1000s of connections. Nginx does not spawn a new process or thread for every connection.

NGINX has a range of capabilities. Some of the most common ones are - 
Web Server
Reverse Proxy
Load Balancing
Content Caching

With NGINX, you can get ten times better performance than the traditional process-driven architecture, along with better resource utilization.
It is also one of the very few tools that can be upgraded without any downtime. It is also highly scalable and easy to maintain. Using NGINX can significantly improve the performance of any server.



Apache Kafka in 3 mins -

Kafka is the most popular and commonly used messaging queue. It is a distributed event streaming platform that allows multiple services to communicate with each other by sending and receiving data using its queue-based architecture.

Distributed? 
Kafka works as a cluster of one or more nodes working together to make it scalable, available, and fault-tolerant.

Event streams? 
These are just infinite data of any type and this data can be processed in real time. In Kafka, a message is the atomic unit of data.

In simpler words, Kafka is a set of machines working together to be able to handle and process real-time infinite data.


With that getting out of the way, let's understand the basic terminology surrounding Kafka -

Broker - A Kafka cluster is made up of one or more servers that work in conjunction with each other. Each of these servers is called a broker.

Publisher/Consumer - The services that produce these events to Kafka broker are referred to as Producers and those that consume these events are referred to as Consumers.

Topic - Data in a queue can be of multiple types. We can classify this data according to our needs for easier access and by doing so, we ensure that any consumer can easily access only that data which is useful for it.

Partition - Any topic can further be divided into partitions to achieve higher throughput and availability. You can think of it like sharding(not exactly). This is what makes Kafka scalable. These partitions can be present on multiple brokers.

Replication - Partitions of data stored on a node are further replicated onto multiple other nodes to ensure fault tolerance. When one broker goes down, data replicated on other brokers can make up for it.

Leader - For any partition, among all replications, one replication is chosen as a Leader. A leader can perform both read and write operations while all other replications can only read data.

Zookeper - Kafka can not run without Zookeper. You can imagine this as a central entity that takes care of the brokers, topics, and partition assignment, leader election, basically all the metadata about the Kafka cluster.


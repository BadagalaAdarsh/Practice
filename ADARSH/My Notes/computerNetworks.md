# Computer Networks Notes

### Define Networks

* A network consists of two or more computers that are linked in order to share the resources (such as printers and CD's), exchange files or allow electronic communications. The computer on a network may be linked through cables, telephone lines, radio waves, satellites or infrared light beams

* Two very common types of networks are LAN and WAN

#### LAN (Local Area Network)

* A local area network (LAN) is a network that is confined to relatively small area. It is generally limited to a geographic area such as writing lab, school or building

* On a single LAN, computers and servers may be connected by cables or wirelessly. Wireless acess to a wired network is made possibly by wireless acess poitns (WAP). These WAP devices provide bridge between computers and networks. A typical WAP might have the theorectical capacity of serving hundreds or even thousands of wireless users to a network, although practical capacity might be far less.

* Nearly always the server will be connected by cables of the network, because the cable connnections tend to be remain the fastest .


#### WAN (Wired Area Network) 

* Wide Area Network (WANs) connect networks in larger geographic areas, such as Florida, United States or the world. Dedicated transcoding cabling or satellite uplinking may be used to connect this types of gloabl networks.

* Using WAN, schools in florida can communicate with the schools in the Japan in a matter of seconds

#### What do you mean by network topology, and explain types of them?

* Network topology refers to the physical or logical layout of the network. 
* There are basically two types of network topologies: physical and logical
* **Physical** topology emphasizes the physical layout of the connected devices and nodes
* **Logical** topology focuses on the pattern of data transfer between network nodes

**Other Definition as per GFG**

* The arrangement of a network that comprimises nodes and connecting lines via sender and receiver is referred to as network topology. The various types of network topologies are

#### Mesh Topology

* In a mesh topology, every device is connected to another device via a particular channel

![Image](https://media.geeksforgeeks.org/wp-content/uploads/1-75.png)

* In the above figure you can see that every device is connected with another device via dedicated channels. These channels are known as links.

**Advantages of this topology**

* it is robust
* The fault is diagnosed easily. Data is realiable because data is transfered among the devices through dedicated channels or links
* Provides security and privacy

**Problems with this topology**

* Installation and configuration of this topology is difficult
* the cost of cable is high as bulk wiring is required , hence suitable for less number of devices
* The cost of maintenance is high

#### Star Topology

* In star topology, all the devices are connected to a central hub through cable. this hub is the central node and all other nodes are connected to the central node. the hub can be passive in natural i.e, not an intelligence hub such as broadcasting devices, at the same time the hub can be intelligent known as an active hub. Active hubs have repeaters in them.

![Image](https://media.geeksforgeeks.org/wp-content/uploads/2-49.png)

**Advantages of this topology**

* If N devices are connected to each other in the star topology, then the number of cables required to connect them is N. so, it is easy to set up.
* Each device requires only 1 port i.e to connect to the central hub, therefore the total number of ports required are the N

**Disadvantages of this topology**

* If the concetrates (hub) on which the whole topology relies fails, the whole system will crash down
* the cost of installation is high
* Performance is based on the single concentrator i.e hub

#### Bus Topology

* Bus topology is a network type in which every computer and network device is connected to a single cable. It transmits the data from one end to another in single direction. No bi-directional feature is in Bus Topology. It is a multipoint connection and non - robust topology because if the backbone fails then the topology crashes.

![image](https://media.geeksforgeeks.org/wp-content/uploads/3-55.png)

**Advantages of this topology**

* If N devices are connected to each other in bus topology, then the number of cables required to connect them is 1, which is known as Backbone cable, N drop lines are required
* The cost of cables is less when compared with the other topologies, but it is used to build the small networks.

**Problems with this topology**

* If the common cable fails then the whole system will crash
* If the network traffic is heavy, it increases collisions in the network. To avoid this, various protocols are used in the MAC layer knows as Pure Aloha, Slotted Aloha, CSMA/CD etc.
* Security is very low

#### Ring Topology

* In this topology, it forms a ring connecting devices with its exactly two neighbouring devices
* A number of repeaters are used for Ring topology with a large number of nodes, because if someone wants to send data to the last node in the ring topology with 100 nodes, then the data will have to pass through 99 nodes to reach the 100th node. Hence to prevent the data loss repeaters are used in the network
* the transmission is unidirectional but it can be made bi-directional by having 2 connections between each network node. It is called dual ring topology

![Image](https://media.geeksforgeeks.org/wp-content/uploads/4-32.png)

**following operations take place in the ring topology**

* One station is known as *monitor* station which takes all the responsibilites to perform the operations
* to transmit the data, the station has to hold the token. After the transmission is done, the token is to be released for other stations to use
* When no station is transmitting the data, then the token will circulate in the ring
* There are two types of token release techniques: **Early token release** releases the token just after transmitting the data and the **Delay token release** releases the token after the acknowledgement is received from the receiver

**Advantages of this topology**

* The possibility of collision is minimum in this type of topology
* Cheap to install and expand

**Problems with this topology**

* Troubleshooting is difficult in this topology
* The addition of stations in between or removal of stations can disturb the whole topology
* Less secure

#### Tree Topology

* this topology is the variation of star topology. This topology has hierarchical flow of data

![Image](https://media.geeksforgeeks.org/wp-content/uploads/20200614134830/tree-topology2.png)

* Here various secondary hubs are connected to the central hub which contains the repeater. In this data flow from top to bottom i.e. from the central hub to secondary and then to the device or from bottom to top i.e devices to the secondary hub and then to central hub. It is a mulitpoint connection and a non-robust topology because if the backbone fails the topology crashes

**Advantages of this topology**

* It allows more devices to be attached to a single central hub thus it decreases the distance that is traveled by the signal to come to the devices
* It allows the network to get isolate and also prioritize from different computers

**Problems with this topology**

* If the central hub fails then the entire system fails
* The cost is high because of cabling

#### Define Bandwidth

* Network bandwidth is a measurement indicating the maximum capacity of a wired or wireless communication link to transmit data over a network connection in a given amount of time. Typically bandwidth is represented in the number of bits, kilobits, megabits or gigabits that can be transmitted in 1 second

#### Define node and link

* A node is **an individual processing unit**, it has capability to communicate with other nodes on demand, process the information it receives..
* A link is a physical and logical network component used to interconnect hosts or nodes in the network


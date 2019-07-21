int startserver()
{
	int sd;		/*socket descriptor*/
	int myport;	/*server port*/
	const char *myname;	/*localhost full name*/

	char linktrgt[MAXNAMELEN];
	char linkname[MAXNAMELEN];

	/*
	 call socket function to create TCP socket descriptor
	*/
	sd = socket(PF_INET, SOCK_STREAM, 0);	

	/*
	 call bind function to assign a local address to socket
	*/
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);/*pass-through address INADDR_ANY said the IP is 0.0.0.0,
							     the kernel will select a local address after the socket is connected,
							     the htonl function is used to reserve INADD_ANY into network byte order.   
							   */
	server_address.sin_port = htons(0);	/*assigned as a wildcard port 0, the kernel will arbitrarily select a temporary port 
						  after bind function is called.
						*/
	bind(sd, (struct sockaddr *)server_address, sizeof(server_address));
}	

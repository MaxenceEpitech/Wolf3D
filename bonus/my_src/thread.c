/*
** thread.c for thread in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Jun  6 17:34:54 2017 fourrier maxence
** Last update Thu Jun  8 13:28:15 2017 fourrier maxence
*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <pthread.h>

#include "my.h"

void			*send_thread(void *arg)
{
  int			sock;
  struct sockaddr_in	server;
  struct hostent	*hp;
  t_all			*all;

  all = arg;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    pthread_exit(NULL);
  server.sin_family = AF_INET;
  if ((hp = gethostbyname("163.5.220.11")) == 0)
    pthread_exit(NULL);
  memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
  server.sin_port = htons(all->addr.y);
  while (connect(sock, (struct sockaddr *)&server,
                 sizeof(server)) < 0);
  while (1)
    if (send(sock, &(all->player->pos), sizeof(sfVector2f), 0) < 0)
      pthread_exit(NULL);
  pthread_exit(NULL);
}

void			*received_thread(void *arg)
{
  int			sock;
  int			mysock;
  int			rval;
  struct sockaddr_in	server;
  t_all			*all;

  all = arg;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    pthread_exit(NULL);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(all->addr.x);
  if (bind(sock, (struct sockaddr*)&server, sizeof(server)))
    pthread_exit(NULL);
  listen(sock, 5);
  if ((mysock = accept(sock, (struct sockaddr*) 0, 0)) == -1)
    pthread_exit(NULL);
  while (1)
    if ((rval = recv(mysock, &(all->pos), sizeof(sfVector2f), 0)) < 0)
      pthread_exit(NULL);
  pthread_exit(NULL);
}

int		init_thread(t_all *all)
{
  pthread_t	receivedthread;
  pthread_t	sendthread;

  if (all->addr.x != 0)
    {
      if (pthread_create(&receivedthread, NULL, received_thread, (t_all*)all))
	return (84);
      if (pthread_create(&sendthread, NULL, send_thread, (t_all*)all))
	return (84);
    }
}

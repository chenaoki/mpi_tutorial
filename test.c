#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 200
int main(int argc, char* argv[]){
  
  int my_rank;
  char message[LENGTH];
  int dest = 0;
  int tag = 0;
 
  // 初期化
  MPI_Init(&argc, &argv);
  
  // プロセス・ランク
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  if(my_rank!=0){ // 送信側

    sprintf(message, "Hello, my proc rank : %d", my_rank);
    MPI_Send( message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD); 

  }else{ // 受信側

    int proc_num;
    int source;
    MPI_Status recv_status;

    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);

    for(source=1; source<proc_num; source++){
      MPI_Recv(message,LENGTH, MPI_CHAR, source, tag, MPI_COMM_WORLD, &recv_status);
      fprintf(stdout, "%s\n", message);
    }
  }
  MPI_Finalize();
}

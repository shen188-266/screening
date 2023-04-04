screen:
	gcc main.c parse.c .\third_party\cJSON\cJSON.c -o screen
clean:
	rm *.o screen -rf
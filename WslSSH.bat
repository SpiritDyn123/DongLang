for /f "tokens=*" %%i in ('wsl hostname -I') do set WSL_IP=%%i  
echo The WSL IP address is: %WSL_IP% 

netsh interface portproxy add v4tov4 listenport=2232 listenaddress=0.0.0.0 connectport=2232 connectaddress=%WSL_IP% 
pause
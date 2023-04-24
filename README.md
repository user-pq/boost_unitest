# boost_unitest
boost unitest framework and example

1、拉取下来进入到该目录下，运行 b2, 对src中的cpp文件进行编译生成动态库

2、运行 b2 install，将生成的动态库安装到lib(会在当前文件夹创建lib文件夹)文件夹中

3、进入到unitest文件夹中，运行b2，运行单元测试用例

注：

运行b2之前请先配置boost环境以及设置环境变量
 

boost环境配置
1、解压boost_1_62_0.tar.gz

   tar -zxvf boost_1_62_0.tar.gz
   
2、运行bootstrap.sh，检查安装环境，若报错，对报错的相应文件进行安装
   
   ./bootstrap.sh

3、运行b2,编译库
 
  ./b2

4、将b2复制一份到/usr/bin
  
  sudo cp ./b2 /usr/bin
   
  which b2

5、根据路径设置环境变量

  设置完以后: source set_env.sh 立即生效 
  

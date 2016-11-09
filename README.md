### This is an branch of pdns for grpc backend

Based on pdns rec-4.0.3

#### Support
|Item| Support |
| :-------- | --------:|
|Native | yes |
|Master| no |
|Slave| no |
|Superslave| no |
|Autoserial| no |
|DNSSEC| no |
|Multiple instances| no |

#### How to

 ```
  $ ./bootstrap
  $ ./configure --with-modules="grpc" 
  $ make
 # make install
 ```

**pdns.conf**

```
# specify the grpc backend host and por
grpc-connection-string=localhost:50051

lannch=grpc
```

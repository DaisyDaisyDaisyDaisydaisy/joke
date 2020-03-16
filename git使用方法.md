## GIT的基本使用方法

*source from:https://blog.csdn.net/weixin_42902669/article/details/103733304*

### 一、基本操作

#### 克隆到本地文件夹

```
git clone 
```

#### 创建远程仓库

```
// 关联远程仓库
git remote add origin git@github.com:path/repo-name.git

// 第一次向远端推送
git push -u origin master
// 后面同步更新
git push origin master
```

#### 添加用户

```
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```

#### 提交前准备

```
git log         // 查看日志
git add .       // 添加到暂存区
```

#### 添加注释

```
git commit -m "注释的内容"
```

#### 提交

```
git push
```



### 二、分支管理

#### 创建/切换分支

```
git branch dev        // 创建分支
git checkout dev      // 切换分支
git checkout -b dev   // 创建并切换分支
git branch            // 查看当前分支
```

```
//方式2
git switch -c dev
```

#### 合并分支

```
git merge dev                 // 合并指定分支到当前分支
git merge --no-ff -m "" dev   
// 禁止Fast forward的合并, 好处是记录了合并信息, 否则无法知道是否有合并发生
```

#### 删除分支

```
git branch -d dev              // 删除本地分支
git push origin --delete dev   // 删除远程分支
```



### 三、回滚/恢复操作

#### 查看日志

```
git log       // 可以看到每次提交的信息和 commit id
git reflog    // 查看历史输入命令
```

#### 暂存区/版本回退

```
git reset HEAD file_name     // 将暂存区修改回退
git reset --head HEAD^       // 回退到上个版本
git reset --head HEAD~n      // 回退到前n个版本
git reset --head commit-id   // 回退到指定版本
```

#### 撤销修改

```
//场景1：撤销工作区的修改
git checkout --file

//场景2：撤销暂存区的修改
git reset HEAD <filename>  //回到场景1的状态
git checkout --file  //执行场景1的操作

//场景3：撤销本地分支还未推送到远程库的修改
reset //使用reset回退到指定版本

```

#### 从版本库中进行删除

```
git rm file_name
git commit -m "可附加本次删除的原因"
```



### 四、同步更新

#### 本地dev分支更新同步到远端master分支

```
git checkout master         // 切换到本地 master 分支
git merge dev               // 将 dev 分支更新合并到本地 master 分支
git push -u origin master   // 将本地 master 更新同步到远端 master
```

远端master分支更新同步到本地及远端dev分支

```
git checkout master       // 切换到本地 master 分支
git pull                  // 将远端 master 分支更新同步到本地 master 分支
git checkout dev          // 切换到本地 dev 分支
git merge master          // 将本地 master 更新同步到本地 dev 分支
git push -u origin dev    // 将本地 dev 分支更新同步到远端 dev 分支
```


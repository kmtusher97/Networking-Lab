%probability states vefore normalization in matrix form
A1=1;A2=2;
x1=2;x2=3;
BW=9;M=ceil(BW/x1); %M by M matrix
for i=1:M
    for j=1:M
        e=(i-1)*x1+(j-1)*x2;
        if e<=9
            S(i,j)=((A1^(i-1))/factorial(i-1))*((A2^(j-1))/factorial(j-1));
        else
            S(i,j)=0;
        end
    end
end
S
%rows should be changed to cope with cartesian co-ordinate system
for i=1:M
    for j=1:M
        k=M-i+1;
        S1(i,j)=S(k,j); %states are now S1(x,y)
    end
end
S1
%normalized states
T=sum(sum(S1));
sn=S1/T;
sn

%side open states
B2=0;
for i=1:M
    for j=1:M
        k=j+1;
        if sn(i,j)>0 && sn(i,k)==0
            B2=B2+sn(i,j);
        end
    end
end
B2

%open side of roof
B1=0;
for i=2:M
    %index of row with k=i-1 cannot be 0
    for j=1:M
        k=i-1;
        if sn(i,j)>0 && sn(k,j)==0
            B1=B1+sn(i,j);
        end
    end
end
B1

%sn(1,1) is the default open state of roof
B1=B1+sn(1,1);
B1

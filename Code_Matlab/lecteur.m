fid = fopen("resultat.txt","r+");
B=zeros(256,256);
% for i = 1:256
%    for j = 1:256
%         tmp = fscanf(fid,'%f\t');
%         fprintf(fid,'(%d,%d)\t',i,j);
%         B(i,j) = tmp;
%    end
%    fscanf(fid,'\n');
%    %fprintf(fid,'\n');
% end

tmp = fscanf(fid,'%f\t',[256 256]);
tmp2 = uint8(tmp);
img1 = zeros(256,256);
for i = 1:256
    for j = 1:256
        img1(i,j)=tmp2(i,j);
    end
end

fclose(fid);

figure
colormap('gray');
imagesc(img1);

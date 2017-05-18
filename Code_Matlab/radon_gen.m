function [ I,R, xp ] = radon_gen( n, theta_max,p )
%transformer de radon
%n la taille de l'imge, theta_max l'angle maximun et p le pas angulaire
I = phantom('Modified Shepp-Logan',n);
%subplot(3,1,1);
% figure
% imshow(I);

theta = 1:p:theta_max; %nombre d'angle lors de la transformer de radon
[R,xp]=radon(I,theta);
%subplot(3,1,2);
% figure
% colormap('gray');
% imagesc(theta,xp,R);

end


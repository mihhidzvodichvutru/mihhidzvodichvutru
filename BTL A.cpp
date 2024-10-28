#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<list>
#include<sstream>
#include<iomanip>
#include<ctype.h>
using namespace std;
class Sinhvien{
	string hoten;
	string masv;
	int year;
	float gpa;
	public:
		void viethoa(){
			for(int i=0;i<hoten.size();i++){
				hoten[i]=toupper(hoten[i]);
			}
		}
		int tinhtuoi(int namht){
			return namht-year;
		}
		bool operator<(const Sinhvien &sv) const{
			return this->hoten<sv.hoten;
		}
     friend istream& operator>>(istream& is ,Sinhvien &sv){
     	cout<<"Nhap thong tin:"<<endl;
     	cout<<"Ho ten:";
     	fflush(stdin);
     	getline(is,sv.hoten);
     	cout<<"Ma sinh vien:";
     	fflush(stdin);
     	getline(is,sv.masv);
     	cout<<"Nam sinh:";
     	is>>sv.year;
     	cout<<"GPA:";
     	is>>sv.gpa;
     	return is;
     	
	 }
	 friend ostream& operator<<(ostream& os,Sinhvien &sv){
	 	cout<<"Ho ten:";
	 	os<<sv.hoten<<endl;
	 	cout<<"Ma sinh vien:";
	 	os<<sv.masv<<endl;
	 	cout<<"Nam sinh:";
	 	os<<sv.year<<endl;
	 	cout<<"GPA:";
	 	os<<fixed<<setprecision(2)<<sv.gpa<<endl;
	 	return os;
	 }
	 string getName(){
	 	return hoten;
	 }
	 float getYear(){
	 	return year;
	 }
	 float getGpa(){
	 	return gpa;
	 }
	 string getMa(){
	 	return masv;
	 }
};
void swap(Sinhvien &x ,Sinhvien &y){
	Sinhvien tmp=x;
	x=y;
	y=tmp;
}
template<class Y>
void max( Sinhvien x, Sinhvien y){
	return (x.getGpa()>y.getGpa())? x.getGpa(): y.getGpa();
}
class DanhsachSinhvien{
	vector<Sinhvien> sinhvienchan;
	public:
		void addsv(){
			Sinhvien sv;
			cin>>sv;
				sinhvienchan.push_back(sv);
    	}
	    void inds(){
	    	cout<<"Danh sach sinh vien vua nhap la:\n";
	    	if(sinhvienchan.size()==NULL){
	    		cout<<"Khong co sinh vien!!"<<endl;
			}
	    	for(vector<Sinhvien>::iterator it=sinhvienchan.begin();it!=sinhvienchan.end();it++){
	    		cout<<endl;
	    		cout<<*it<<endl;
	    		cout<<endl;
			}
		}
		void sapxepten(){
			sort(sinhvienchan.begin(),sinhvienchan.end());
		}
		void sapxepgpatang(){
			for(size_t i=0;i<sinhvienchan.size()-1;i++){
				for(size_t j=i+1;j<sinhvienchan.size();j++){
					if(sinhvienchan[i].getGpa()>sinhvienchan[j].getGpa()){
						swap(sinhvienchan[i],sinhvienchan[j]);
					}
				}
			}
		}
		void viethoaten(){
			for(size_t i=0;i<sinhvienchan.size();i++){
				    sinhvienchan[i].Sinhvien::viethoa();
			}
		}
		void intuoi(){
			int present;
			cout<<"Nam hien tai:";
			cin>>present;
			cout<<"Danh sach sinh vien va tuoi hien tai:\n";
			for(size_t i=0;i<sinhvienchan.size();i++){
				cout<<"Ho ten:"<<sinhvienchan[i].getName()<<"-"<<"Tuoi hien tai:"<<sinhvienchan[i].tinhtuoi(present)<<endl;
			}
		}
		void suathongtin(){
			int stt;
			cout<<"Nhap so thu tu sinh vien can sua:";
			cin>>stt;
			int i=stt-1;
			sinhvienchan.erase(sinhvienchan.begin()+i);
			Sinhvien sv;
			cin>>sv;
			sinhvienchan.insert(sinhvienchan.begin()+i,sv);
		}
		void xoasinhvien(){
			int stt;
			cout<<"Nhap so thu tu sinh vien can xoa:";
			cin>>stt;
			int i=stt-1;
			sinhvienchan.erase(sinhvienchan.begin()+i);
		}
		void CodeSearching(){
			string xau_ki_tu;
			cout<<"Nhap ma sinh vien can tim kiem:";
			fflush(stdin);
			getline(cin,xau_ki_tu);
			for(vector<Sinhvien>::iterator it=sinhvienchan.begin();it!=sinhvienchan.end();it++){
				if(it->getMa()==xau_ki_tu){
					cout<<*it<<endl;
				}else{
					cout<<"Khong co sinh vien!";
				}
			}
		}
		void Timkiemmax(){
			float MaxGpa=sinhvienchan[0].getGpa();
			for(size_t i=1;i<sinhvienchan.size();i++){
			    MaxGpa=max(MaxGpa,sinhvienchan[i].getGpa());
			}
			for(vector<Sinhvien>::iterator it=sinhvienchan.begin();it!=sinhvienchan.end();it++){
				 if((it->getGpa()==MaxGpa)){
				 	cout<<*it<<endl;
				 }
			   }
			}
};
class App{
   DanhsachSinhvien listsv;
   public:
      void Options(){
      	  while(1){
      	  	cout<<"------------MENU-------------"<<endl;
      	  	cout<<"1.Them sinh vien"<<endl;
      	  	cout<<"2.In danh sach sinh vien hien tai"<<endl;
      	  	cout<<"3.Sap xep sinh vien theo ten"<<endl;
      	  	cout<<"4.Tuoi sinh vien hien tai"<<endl;
      	  	cout<<"5.Viet hoa ten cac sinh vien"<<endl;
      	  	cout<<"6.Sua lai thong tin sinh vien"<<endl;
      	  	cout<<"7.Xoa sinh vien"<<endl;
      	  	cout<<"8.Sap xep theo diem GPA tang dan"<<endl;
      	  	cout<<"9.Tim kiem theo ma sinh vien"<<endl;
      	  	cout<<"10.Sinh vien co diem GPA cao nhat"<<endl;
      	  	cout<<"11.Thoat chuong trinh"<<endl;
      	  	cout<<"Nhap lua chon:";
      	  	int lc;
      	  	cin>>lc;
      	  	if(lc==1){
      	  		listsv.addsv();
			}else if(lc==2){
				listsv.inds();
			}else if(lc==3){
				listsv.sapxepten();
			}else if(lc==4){
			    listsv.intuoi();
			}else if(lc==5){
				listsv.viethoaten();
			}else if(lc==6){
				listsv.suathongtin();
			}else if(lc==7){
				listsv.xoasinhvien();
			}else if(lc==8){
				listsv.sapxepgpatang();
			}else if(lc==9){
				listsv.CodeSearching();
			}else if(lc==10){
				listsv.Timkiemmax();
			}else if(lc==11){
				char option;
				cout<<"Xac nhan thoat:Y/N ?";
				cin>>option;
				if(option=='Y'){
					break;
				}else{
					continue;
				}
			}

		}
  
  }
};

main(){
	App quanlisinhvien;
	quanlisinhvien.Options();
	cout<<"Written by DMH!";
	cout<<endl<<"Thanks for using!";
}

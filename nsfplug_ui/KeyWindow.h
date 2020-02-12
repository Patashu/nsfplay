#pragma once
// KeyWindow �_�C�A���O

class KeyWindow : public CDialog
{
	DECLARE_DYNAMIC(KeyWindow)

public:
	KeyWindow(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~KeyWindow();

  // �L�[�{�[�h��`��
  virtual void draw_keyboard(CDC *pDC, int x, int y, int nx, int ny);
  // ���Չ�����Ԃ�`��
  virtual void draw_notes(CDC *pDC, int x, int y, int nx, int ny);

  // �L�[�I���ʒm
  virtual void KeyOn(int note, int color=0xFF0000);
  // �L�[�I�t�ʒm
  virtual void KeyOff(int note);
  // �S�ăL�[�I�t
  virtual void Reset();

  virtual void TrackOn(int track, int color, int volume, double fractionalNote, int frame);

  inline int MinWidth(){ return 366+1; }
  inline int MaxWidth(){ return synthesiaWidth; }
  inline int SynthesiaHeight(){ return synthesiaHeight; }
  int synthesiaHeight;
  int synthesiaWidth;
  int startingOctave;

  // �`�悵���L�[�{�[�h���i�[
  CBitmap m_keyBitmap;
  CDC m_keyDC;

  // �L�[�{�[�h�K�C�h�\���p
  CBitmap m_digBitmap;
  CDC m_digDC;

  // ����ʗ̈�
  CBitmap m_memBitmap;
  CDC m_memDC;

static const int MAX_FRAMES = 10;
static const int NUM_OCTAVES = 10;

  // ������ԃt���O
  int m_nKeyStatus[256];
  // ��������F
  int m_nKeyColor[256];

  //backside
  int numberofframes;
  //int lastnumberofframes;
  int synth_speed;
  int sharp_brightness;

  static const int NES_TRACK_MAX = 31;

  //xgm::ITrackInfo* m_nTrackInfo[NES_TRACK_MAX][MAX_FRAMES];
  int m_nTrackStatus[NES_TRACK_MAX][MAX_FRAMES];
  int m_nTrackColor[NES_TRACK_MAX][MAX_FRAMES];
  int m_nTrackVolume[NES_TRACK_MAX][MAX_FRAMES];
  double m_nTrackFractionalNote[NES_TRACK_MAX][MAX_FRAMES];
  int numberoftracks;

  // �����������t���O
  bool m_bInit;
  // �I�N�^�[�u�K�C�h�\��ON/OFF
  bool m_bShowOctave;



// �_�C�A���O �f�[�^
	enum { IDD = IDD_KEYWINDOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnPaint();
  afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
  virtual BOOL DestroyWindow();
};
